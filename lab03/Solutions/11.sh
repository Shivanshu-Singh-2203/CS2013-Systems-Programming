# For each line in 'data/12.txt':
# - Split the line into fields separated by spaces
# - The last field contains 'rollnumber@hostname'
# - Extract the roll number by removing the '@hostname' part
# - Create a file named '<rollnumber>.pub' in 'output/12/'
# - Write the entire SSH key line into that file
# - Repeat for every line so that each student has a separate .pub file

cd ../data
mkdir -p ../output/12
cat 12.txt | awk -F'[@ ]' '{print $0 > "../output/12/"$3".pub" }'
