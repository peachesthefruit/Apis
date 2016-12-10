#!/usr/bin/env sh

# This file can be used to setup the Apis project
# Use source to ensure environment variables are set correctly,
# do not run with bash or sh

# Attempt to set up python
echo $'\nSetting up Python, requires Python3.5 and pip3.5'
echo $'\nSetting up Python, requires Python3.5 and pip3.5' >> apis.log
PIP_PATH=$(which pip3.5)
(pip3.5 install -r requirements.txt >> apis.log) ||
    (echo 'Might need root for python install, attempting to sudo' && 
    sudo -H $PIP_PATH install -r requirements.txt >> apis.log)
export FLASK_APP=hive.py
chmod +x scout.py
chmod +x apis.py

if [ $? != 0 ]; then
    echo 'Error with Python setup, check apis.log for details'
    exit 1
fi
echo $'Done\n'

# Attempt to make C++ files
echo 'Buidling C++ files'
echo $'\nBuidling C++ files' >> apis.log
make >> apis.log
if [ $? != 0 ]; then
    echo 'Error with C++ setup, check apis.log for details'
    exit 2
fi
chmod +x benchmark.sh
echo $'Done\n'
