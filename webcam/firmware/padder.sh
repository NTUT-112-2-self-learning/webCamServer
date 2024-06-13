#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: ./padder.sh <input_file> <output_file>"
    exit 1
fi

# Create a binary file filled with 1's
dd if=/dev/zero bs=1 count=16777216 | tr "\0" "\377" > $2

# Load the input file from address 0x0
dd if=$1 of=$2 conv=notrunc

exit 0