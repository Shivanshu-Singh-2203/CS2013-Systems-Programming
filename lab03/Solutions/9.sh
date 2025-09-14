#!/bin/sh

# Convert the text file 'data/10.txt' to CSV format
# - The original file has fields separated by spaces
# - Replace all spaces between fields with commas
# - Preserve the order of the data exactly as in the original file
# - Do not add a header line
# - Ensure no spaces exist between the commas
# - Save the output as 'output/10.csv'

sed 's/ \+/,/g' ../data/10.txt > ../output/10.csv

