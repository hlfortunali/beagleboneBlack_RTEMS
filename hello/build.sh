#! /bin/bash

./waf && cd ./build/arm-rtems6-beagleboneblack && pwd && ./rtems_generate_img.sh