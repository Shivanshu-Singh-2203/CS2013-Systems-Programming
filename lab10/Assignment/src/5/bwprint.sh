#!/bin/bash

mkdir -p "BW print"

for i in images/*; do        
    filename=$(basename "$i")          
    ./bwprint "$i" "BW print/$filename"
done

