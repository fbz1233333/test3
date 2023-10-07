#!/bin/bash

foldername="build"

if [ -d "$foldername" ]; then
    echo "-- folder has exist"
else
    mkdir "$foldername"
    echo "-- create folder "
fi

cd build && cmake .. && make && cd .. && ./build/main
