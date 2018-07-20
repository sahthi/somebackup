@echo off


call bluebank_amss_env.cmd
set HOME_DIR=%cd%
set TOTAL_MODEM_BUILD_STEP=5
set CURRENT_STEP=0
echo %HOME_DIR%

set MOD=%1
set BOC=%2

set BUILD_START=%TIME%

if "%1"==""  goto usage
if "%2"=="b" goto continue
if "%2"=="c" goto continue
if "%2"==""  goto continue
goto usage
:continue
if %1==ALL	goto MPSS
if %1==MPSS goto MPSS
if %1==RPM  goto RPM
if %1==BOOT goto BOOT
if %1==TZ   goto TZ


:usage
echo USAGE:
echo "%0 ALL (build all (frist clean, then build 	)"
echo "%0 MPSS [c|b] ( c for clean modem_proc , b for build modem_proc  , empty for clean+build)"
echo "%0 RPM [c|b] ( c for clean rpm_proc , b for build rpm_proc  ,empty for clean+build)"
echo "%0 BOOT [c|b] ( c for clean boot_images , b for build boot_images ,empty for clean+build)"
echo "%0 TZ [c|b] ( c for clean trustzone_images , b for build trustzone_images  ,empty for clean+build)"
goto eof

@REM
@REM start build MPSS 
:MPSS 
set TITLE_B=(MPSS)modem_proc
set BUILD_DIR="modem_proc\build\ms" 
set CLEAN_CMD=build.cmd 8909.lwg.prod -c
set BUILD_CMD=build.cmd 8909.lwg.prod MCFG_HW_PRODUCT=generic/common/MSM8909 MCFG_HW_TYPE=SS-LA -k
set /a CURRENT_STEP=  %CURRENT_STEP%+1

call:BUILD_MODULE
if %1==MPSS goto end

@REM
@REM start build RPM 
 
:RPM
set TITLE_B=(RPM)rpm_proc
set BUILD_DIR="rpm_proc\build" 
set CLEAN_CMD=build_8909.bat -c
set BUILD_CMD=build_8909.bat
set /a CURRENT_STEP=  %CURRENT_STEP%+1

call:BUILD_MODULE
if %1==RPM goto end
@REM
@REM start build BOOTLOADER  
:BOOT
set TITLE_B=(BOOT)boot_images_DDR3
set BUILD_DIR="boot_images\build\ms" 
set CLEAN_CMD=build.cmd TARGET_FAMILY=8909 --prod -c
set BUILD_CMD=build.cmd TARGET_FAMILY=8909 --prod
set /a CURRENT_STEP=  %CURRENT_STEP%+1
@rem =========================DDR3 compatible=======================================
@REM build DDR3  first 
type   bluebank_ddrcfg\boot_config_data_compatible.c > boot_images\core\boot\secboot3\src\boot_config_data.c
call:BUILD_MODULE
echo backup DDR3 to  boot_images/build/ms/bin/8909/emmcDDR3
rmdir boot_images\build\ms\bin\8909\emmcDDR3  /s/q
move  boot_images\build\ms\bin\8909\emmc   boot_images\build\ms\bin\8909\emmcDDR3 

@rem ===========================DDR3 only=====================================

set TITLE_B=(BOOT)boot_images_DDR3_only
set BUILD_DIR="boot_images\build\ms" 
set CLEAN_CMD=build.cmd TARGET_FAMILY=8909 --prod -c
set BUILD_CMD=build.cmd TARGET_FAMILY=8909 --prod
set /a CURRENT_STEP=  %CURRENT_STEP%+1
@REM build DDR3  only version 
type   bluebank_ddrcfg\boot_config_data_ddr3_only.c > boot_images\core\boot\secboot3\src\boot_config_data.c
call:BUILD_MODULE
echo backup DDR3 only to  boot_images/build/ms/bin/8909/emmcDDR3only
rmdir boot_images\build\ms\bin\8909\emmcDDR3only  /s/q
move  boot_images\build\ms\bin\8909\emmc   boot_images\build\ms\bin\8909\emmcDDR3only 

@rem =========================== DDR2 =====================================
@REM build normal DDR2 second
set TITLE_B=(BOOT)boot_images_DDR2
set BUILD_DIR="boot_images\build\ms" 
set CLEAN_CMD=build.cmd TARGET_FAMILY=8909 --prod -c
set BUILD_CMD=build.cmd TARGET_FAMILY=8909 --prod
set /a CURRENT_STEP=  %CURRENT_STEP%+1
type   bluebank_ddrcfg\boot_config_data.c > boot_images\core\boot\secboot3\src\boot_config_data.c
call:BUILD_MODULE
@rem ================================================================

if %1==BOOT goto end


@REM
@REM start build TZ  
:TZ
set TITLE_B=(TZ)trustzone_images
set BUILD_DIR="trustzone_images\build\ms" 
set CLEAN_CMD=build.cmd CHIPSET=msm8909 tz sampleapp tzbsp_no_xpu playready widevine keymaster commonlib -c
set BUILD_CMD=build.cmd CHIPSET=msm8909 tz sampleapp tzbsp_no_xpu playready widevine keymaster commonlib

set /a CURRENT_STEP=  %CURRENT_STEP%+1



call:BUILD_MODULE 
if %1==TZ goto end  

goto end



::--------------------------------------------------------  
::-- Function section 
::--------------------------------------------------------  

:BUILD_MODULE
cd %BUILD_DIR%
echo "start"
if "%BOC%"=="c" goto CLEAN
if "%BOC%"=="b" goto BUILD
  
:CLEAN
title STEP(%TOTAL_MODEM_BUILD_STEP%--%CURRENT_STEP%)%TITLE_B%   in Cleaning process%
echo "%TITLE_B% clean start++ %date% %TIME%" >>%HOME_DIR%\build_steps.txt
call %CLEAN_CMD%
@rem if errorlevel 1 goto error
echo "%TITLE_B% clean end---- %date% %TIME%" >>%HOME_DIR%\build_steps.txt

if "%BOC%"=="c" goto FUNC_END

:BUILD
title STEP(%TOTAL_MODEM_BUILD_STEP%--%CURRENT_STEP%)%TITLE_B%  in Building process
echo "%TITLE_B% build start++ %date% %TIME%" >>%HOME_DIR%\build_steps.txt
call %BUILD_CMD%
@rem if errorlevel 1 goto error
echo "%TITLE_B% build end---- %date% %TIME%" >>%HOME_DIR%\build_steps.txt
goto FUNC_END
:error
echo ##################################################################################
echo ##############     build has ERROR at %TITLE_B%      STOPED!   ###################
echo ##################################################################################
:FUNC_END
cd %HOME_DIR%
goto eof 

:end
echo "########## Bluebank build start at %BUILD_START%  ,build end %TIME% #############"

:eof

