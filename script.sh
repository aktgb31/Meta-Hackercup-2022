#!/bin/bash
# Bash Script to create directory with given name and copy debug.h in it, create input.txt, output.txt and $DIRECTORY_NAME.cpp
mkdir $1
cp debug.h $1
touch $1/input.txt
touch $1/output.txt
touch $1/$1.cpp
# End of script.sh