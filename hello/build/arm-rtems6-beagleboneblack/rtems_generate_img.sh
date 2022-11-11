#! /bin/bash

echo -e "\nIn build folder, converting exe to img!\n"

arm-rtems6-objcopy hello.exe -O binary app.bin &&
gzip -9 app.bin -f &&
mkimage -A arm -O linux -T kernel -a 0x80000000 -e 0x80000000 -n RTEMS -d app.bin.gz rtems-app.img &&
cp rtems-app.img ~/Documents/tftp_root