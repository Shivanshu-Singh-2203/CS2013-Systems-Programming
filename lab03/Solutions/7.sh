# Loop through all files in the directory 'output/06/'
# Check if the filename contains two consecutive digits anywhere in the name
# If the filename matches the pattern, truncate the file to empty its contents
# Files that do not have two consecutive digits in the name are left unchanged

cd ../output/06/

for i in {0..9}
do
    for file in *"$i$i"*
    do
        [ -f "$file" ] && > "$file"
    done
done
