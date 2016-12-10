#!/usr/bin/env sh

echo $'\nSetting up Python, requires Python3.5 and pip3.5'
echo $'\nSetting up Python, requires Python3.5 and pip3.5' >> apis.log
PIP_PATH=$(which pip3.5)
(pip3.5 install -r requirements.txt >> apis.log) ||
    (echo 'Might need root for python install, attempting to sudo' && 
    sudo $PIP_PATH install -r requirements.txt >> apis.log)
export FLASK_APP=hive.py
if [ $? != 0 ]; then
    echo 'Error with Python setup, check apis.log for details'
    exit 1
fi
echo $'Done\n'
echo 'Buidling C++ files'
echo $'\nBuidling C++ files' >> apis.log
make >> apis.log
if [ $? != 0 ]; then
    echo 'Error with C++ setup, check apis.log for details'
    exit 2
fi
echo $'Done\n'
