# Find unique entries in the file `data/04.txt` and count the number of unique
# elements. Output this count in the file `output/04.txt` as its only content.
#
# Do not forget to sort the file before finding the unique ones.

cd ../
cat data/04.txt | sort | uniq | wc -l > output/04.txt
