#!/bin/bash

sudo apt update
sudo apt upgrade

sudo apt install gdb -y
sudo apt install edb-debugger -y
sudo apt install edb-debugger-plugins -y
sudo apt install meld -y
sudo apt install wxhexeditor -y
sudo apt install zim -y
sudo apt install yara -y
sudo apt install upx-ucl -y

sudo apt autoremove -y

clear

echo "======= YOU NEED TO DOWNLOAD AND INSTALL THESE ======="
echo "* gdb peda"
echo "* ida pro"
echo "* sourcetrail"
echo "* retdec"
echo "* ghidra"
echo "* burp suite"
echo "* 010 editor"
echo "* cutter"
echo "* frida"
echo "* jadx"
echo "* bytecodeviewer"
echo "* hopper"
echo "* binary-ninja"
