#! /bin/bash

echo "building hello.exe"

./waf && cd ./build/arm-rtems6-beagleboneblack && pwd && exec ./rtems_generate_img.sh