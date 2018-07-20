#!/bin/bash
File_list=( 
          "common"
					"wcnss_proc"
					"trustzone_images/build/ms"
					"rpm_proc/build/ms"
					"rpm_proc/core/products"
					"rpm_proc/core/bsp/rpm/build"
					"modem_proc/build/ms/bin"
					"boot_images/core/storage/tools"
					"boot_images/build/ms/bin"
					 
           )
           
for file in ${File_list[@]} 
do 
	git add $file/*	
 	   
done
