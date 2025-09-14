:'Create a folder named `output/` in `lab03` folder. 

Get the first 25 lines of the file `data/03.txt` and the last 15 files of the
file `data/03.txt`. Concatenate the outputs in that order (25 lines first, then
15 lines) and write the result to `output/03.txt` 
'

cd ../
#rm -r output
mkdir -p output
 
head -25 data/03.txt > output/03.txt
tail -15 data/03.txt >> output/03.txt
