#!/bin/bash

echo "################ Begin to pack the images ############"

DEV_IGN_MAKE_SYSTEM_IMG=$1
#echo $TAR_VER	#for test
if [ "$ANDROID_PRODUCT_OUT" == "" ] ; then
echo "You must run lunch <project> first"
exit 1
fi



if  [ $TARGET_BUILD_VARIANT == userdebug ] ; then

       BB_BUILD_VARIANT=${TARGET_BUILD_VARIANT}_f3_signed
	MPSS_FLAVOR=8909.lwgf3.prod
	CONTENT_FILE_FLAVOR=contents_lwgf3.xml
	cp -f contents_lwgf3.xml contents.xml
	
elif   [ $TARGET_BUILD_VARIANT == user ] ; then

        BB_BUILD_VARIANT=${TARGET_BUILD_VARIANT}_signed
	MPSS_FLAVOR=8909.lwg.prod
	CONTENT_FILE_FLAVOR=contents.xml
	git checkout contents.xml

else
	echo "You must run lunch <project> first"
fi
 


if [ $BLUEBANK_TARGET_PRODUCT  == LF2403N_L3_MSM8909_512 ] ; then
TARGET_DDR_DIR=DDR3only
elif [ $BLUEBANK_TARGET_PRODUCT  != LF2403_MSM8909_512 ] ; then
TARGET_DDR_DIR=DDR3
else
TARGET_DDR_DIR=""
fi
 

PROJECT_NAME=
RELEASE_DIR=pub
CUR_DIR=$PWD
SRC_TOP_DIR=$PWD
BUILD_VERSION_INC=

source LINUX/android/version/version_$BLUEBANK_TARGET_PRODUCT.txt

#GET THE ro.build.version.incremental FROM  $ANDROID_PRODUCT_OUT/system/build.prop

if [ ! -f $ANDROID_PRODUCT_OUT/system/build.prop ] ; then
	echo "Can't find necessary file $ANDROID_PRODUCT_OUT/system/build.prop  "
	exit 1
fi

while read line 
do
	#echo $line
	if [[ $line =~ "ro.build.version.incremental" ]] ; then
		BUILD_VERSION_INC=${line##*=}
		#echo $BUILD_VERSION_INC 
		
		break
	fi

done  < $ANDROID_PRODUCT_OUT/system/build.prop 


        
 


#if [ "$TARGET_DDR_DIR" = "" ] ;then 

TAR_VER=${BUILD_VERSION_INC}_${BB_BUILD_VARIANT}
#else
#TAR_VER=${BUILD_VERSION_INC}_${TARGET_DDR_DIR}_${BB_BUILD_VARIANT}
#fi
 
###parameter summary
echo "BUILD_NUMBER: ${BUILD_VERSION_INC}"
set `date +%Y%m%d`
echo "MPSS_FLAVOR         : ${MPSS_FLAVOR}" 
echo "CONTENT_FILE_FLAVOR : ${CONTENT_FILE_FLAVOR}"
echo "TARGET_DDR          :${TARGET_DDR_DIR}"
 

if [ ! -d $RELEASE_DIR ] ; then
	mkdir -p $RELEASE_DIR
else
	 
	if [ -d $RELEASE_DIR/MBN_BACKUP_UNSIGN ] ; then
		echo "MBN_BACKUP_UNSIGN still exist which means mbn backup/restore process not complete in previous pack . Please Check !!!!!! "
		exit 1 
	fi
	rm -fr $RELEASE_DIR/*
fi
mkdir -p $RELEASE_DIR/$TAR_VER
mkdir -p $RELEASE_DIR/MBN_BACKUP_UNSIGN

###sign the mbn process 
rm  ${TAR_VER}.zip
source pack_signed

###update common info process 
cd  common/build
python update_common_info.py
cd -


echo $TAR_VER
cp -f modem_proc/rftarget_jolokia/msm8909/qcn/wtr2965_qrd8905_apt_3p/etc/mars.qcn modem_proc/


#echo "################ zip Images ############" 
File_list=( 
          "common"
					"wcnss_proc/build/ms"
					"wcnss_proc/Pronto/bsp/build"
					"trustzone_images/build/ms"
					"rpm_proc/build/ms"
					"rpm_proc/core/products"
					"rpm_proc/core/bsp/rpm/build"
					"modem_proc/build/ms/bin/${MPSS_FLAVOR}"
					"boot_images/core/storage/tools"
					"boot_images/build/ms/bin/8909/emmc${TARGET_DDR_DIR}"
					"LINUX/android/out/target/product/msm8909_512/system.img"
					"LINUX/android/out/target/product/msm8909_512/userdata.img"
					"LINUX/android/out/target/product/msm8909_512/ramdisk-recovery.img"
					"LINUX/android/out/target/product/msm8909_512/recovery.id"
					"LINUX/android/out/target/product/msm8909_512/recovery.img"
					"LINUX/android/out/target/product/msm8909_512/boot.img"
					"LINUX/android/out/target/product/msm8909_512/ramdisk.img"
					 "LINUX/android/out/target/product/msm8909_512/cache.img"
					 "LINUX/android/out/target/product/msm8909_512/persist.img"
					 "LINUX/android/out/target/product/msm8909_512/usbmsc.img"
					 "LINUX/android/out/target/product/msm8909_512/emmc_appsboot.mbn"
					 "LINUX/android/out/target/product/msm8909_512/oem_fota_meta.zip"
					 "${CONTENT_FILE_FLAVOR}"
					 "modem_proc/mars.qcn"
					 "about.html"
           )
           
for file in ${File_list[@]} 
do 
		cp --parents -fr $file $RELEASE_DIR/$TAR_VER/
		if [ $file == "contents_lwgf3.xml" ] ; then
				mv $RELEASE_DIR/$TAR_VER/contents_lwgf3.xml   $RELEASE_DIR/$TAR_VER/contents.xml
		fi
 	   
done

#use  fs_image.tar.gz.mbn_signed.img  replase  fs_image.tar.gz.mbn.img  ,By Lilikun  for secure boot (20170626 mail mentioned)
rm $RELEASE_DIR/$TAR_VER/common/build/fs_image.tar.gz.mbn.img  
if [ $BLUEBANK_TARGET_PRODUCT  == LF2403S_MSM8909_512 ] ; then
mv $RELEASE_DIR/$TAR_VER/common/build/fs_image.tar.gz.mbn_signed_LF2403S_MSM8909_512.img $RELEASE_DIR/$TAR_VER/common/build/fs_image.tar.gz.mbn.img 
else
mv $RELEASE_DIR/$TAR_VER/common/build/fs_image.tar.gz.mbn_signed.img $RELEASE_DIR/$TAR_VER/common/build/fs_image.tar.gz.mbn.img 

fi
#lijun add for choose different DDR image for project LF2403N_L3_MSM8909_512
if [ ! -d $RELEASE_DIR/$TAR_VER/boot_images/build/ms/bin/8909/emmc ] ;then
	mv $RELEASE_DIR/$TAR_VER/boot_images/build/ms/bin/8909/emmc${TARGET_DDR_DIR}  $RELEASE_DIR/$TAR_VER/boot_images/build/ms/bin/8909/emmc

fi



cp -f LINUX/android/vendor/bluebank/build/flash_tools/* $RELEASE_DIR/$TAR_VER/
cp -f LINUX/android/vendor/bluebank/build/fota_tools/* $RELEASE_DIR/$TAR_VER/
mkdir -p $RELEASE_DIR/$TAR_VER/software_update_tools
cp -f LINUX/android/vendor/bluebank/build/qualcomm_tools/* $RELEASE_DIR/$TAR_VER/software_update_tools/
find ./$RELEASE_DIR/$TAR_VER/common/tools/sectools -name "OEM-KEYS" -type d -print | xargs rm -rf 
cd  $RELEASE_DIR
rm  $TAR_VER.zip

####restore the signed mbn to its unsigned state  
cp -fr  MBN_BACKUP_UNSIGN/*   ../
rm -fr  MBN_BACKUP_UNSIGN


#start zip the release build 
zip -9 -r ${TAR_VER}.zip $TAR_VER 
 
cd ..

rm -f modem_proc/mars.qcn

#### for venus.mbn ,recover the signed venus.* from it's origin
rm -f $ANDROID_PRODUCT_OUT/system.img
rm -f $ANDROID_PRODUCT_OUT/system/etc/firmware/venus.*
cp -f LINUX/android/vendor/qcom/proprietary/prebuilt_HY11/target/product/msm8909_512/system/etc/firmware/venus.*  $ANDROID_PRODUCT_OUT/system/etc/firmware/
 



#pack symbols for QCAP analysis 
if [ ! -d $RELEASE_DIR/${TAR_VER}_symbols_for_qcap ] ;then
   mkdir -p $RELEASE_DIR/${TAR_VER}_symbols_for_qcap
fi
 
bin_list=(           
				"contents.xml"
				"LINUX/android/out/target/product/msm8909_512/obj/KERNEL_OBJ/vmlinux"				
				"LINUX/android/out/target/product/msm8909_512/symbols"
#				"modem_proc/build/ms/*.elf"
#				"modem_proc/build/myps/qshrink/msg_hash.txt"
#				"rpm_proc/core/bsp/rpm/build/"
#				"trustzone_images/core/securemsm/trustzone/qsee/tz*.*"				
           )
           
for file in ${bin_list[@]} 
do 
		cp --parents -fr $file $RELEASE_DIR/${TAR_VER}_symbols_for_qcap/
 	   
done
cd  $RELEASE_DIR
rm  ${TAR_VER}_symbols_for_qcap.zip
zip -9 -r ${TAR_VER}_symbols_for_qcap.zip ${TAR_VER}_symbols_for_qcap
rm -fr ${TAR_VER}_symbols_for_qcap
cd ..
  
 
