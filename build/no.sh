#!/bin/bash

$3/build.sh $@

# run program
$3/main < $3/input
# cleaning up
rm -f $3/main *.o
