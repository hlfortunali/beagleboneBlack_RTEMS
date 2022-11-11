# beagleboneBlack_RTEMS
demo of running RTEMS on beaglebone Black

This is just a simple demo of running RTEMS on Beaglebone Black.   

## Step 1 : build compile tools 
Just follow the official user guide on Chapter 2 - quick start. ( https://docs.rtems.org/branches/master/user/start/index.html)

## Step 2 : build BSP
I reference the manual build chapter（2.5.2. Manual BSP Build）.   Because I found the RSB BSP Build will fail.

## Step 3 : build your own test application
Just follow 2.7. Build Your Application.

## Step 4 : generate img file 
Reference to https://docs.rtems.org/branches/master/user/bsps/arm/beagle.html#bsp-arm-beagleboneblack. 

Mainly use following commands:  
arm-rtems6-objcopy hello.exe -O binary app.bin  
gzip -9 app.bin  
mkimage -A arm -O linux -T kernel -a 0x80000000 -e 0x80000000 -n RTEMS -d app.bin.gz rtems-app.img  

## Step 5 : Boot configure
    >### Generate u-boot with SD card
    >I use the default SD card with U-boot installed.

    >### generate uEnv.txt
    >I do't use the default configure mentioned in 9.2.3.3. Writing the uEnv.txt file.

## Step 6: config tftp on you host computer
Just find a guide on internet. it's very easy.

## Step 7 : start run application
I manually input the loading script after u-boot is on.
There are 2 methods to load img file:
    >### 1, store all the file needed in SD card and use follwing commands:

    >Both rtems-app.img and am335x-boneblack.dtb are needed.

    >fatload mmc 0 0x80800000 rtems-app.img  
    >fatload mmc 0 0x88000000 am335x-boneblack.dtb  
    >bootm 0x80800000 – 0x88000000  

    >### 2, use tftp to transmit the files into Beaglebone
    >tftpboot  0x80800000 rtems-app.img  
    >tftpboot 0x88000000 am335x-boneblack.dtb  
    >bootm 0x80800000 – 0x88000000  

## Then the application is up and you can see the console will print 'hello'.



