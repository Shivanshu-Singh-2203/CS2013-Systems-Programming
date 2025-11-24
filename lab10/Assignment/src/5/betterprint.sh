#!/bin/bash

mkdir -p "Better print"

for i in images/*; do
    filename=$(basename "$i")

    ./betterbwprint "$i" "Better print/$filename"
done

