# Replace all occurrences of the word 'keyboard' with 'leopard' in the file 'data/11.txt'
# - Read the input file line by line
# - Substitute every instance of 'keyboard' with 'leopard'
# - Save the modified content to 'output/11.txt'
# - After running, open 'output/11.txt' to verify that all replacements were made

sed 's/keyboard/leopard/g' ../data/11.txt > ../output/11.txt
