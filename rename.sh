#!/bin/bash

for dir in *
do
    if [ -d "$dir" ] 
    then
        newdir=$(echo "$dir" | sed -e "s/\.\ / /" | tr ' ' _)
        echo $newdir
        mv "${dir}" "${newdir}"
    fi
done
