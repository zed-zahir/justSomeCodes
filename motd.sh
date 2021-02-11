#!/bin/bash

h=`date +%H`

if [ $h -lt 12 ]; then
  echo Good morning ZED
elif [ $h -lt 18 ]; then
  echo Good afternoon ZED
else
  echo Good evening ZED
fi
