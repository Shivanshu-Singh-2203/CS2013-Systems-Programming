# List all files in the directory 'output/06/'
# - 'ls' lists files in the directory
# - The output is filtered by 'grep' to exclude filenames containing '2' or '3'
# - 'grep -v' inverts the match, so lines containing '2' or '3' are removed
# - 'sort' sorts the remaining filenames alphabetically
# - The final sorted list is redirected to 'output/07.txt'

cd ../output/06/
ls | grep -v '[23]' | sort > ../07.txt
