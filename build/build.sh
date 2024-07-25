#!/bin/bash
g++ -g $1/$2 -o $3/main
cp $3/main $1/$4
if [ $? -ne 0 ] 
then
    echo 💥 BUILD ERROR 💥
		exit 1
fi
