# Count all files in 'output/06/' that were NOT emptied in stage 8
# - Only consider regular files (ignore directories)
# - Exclude files with zero size (these were emptied)
# - Use 'wc -l' to get the total number of non-empty files
# - Redirect the resulting count into 'output/09.txt'

cd ../output/06/

find . -type f -size +0c | wc -l > ../09.txt
