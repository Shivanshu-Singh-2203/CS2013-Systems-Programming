:'Download all the 12 files residing at the URLs given below

- http://10.129.4.1/cs2013/lab03/f/03.zip
- http://10.129.4.1/cs2013/lab03/f/04.zip
- http://10.129.4.1/cs2013/lab03/f/05.zip
- http://10.129.4.1/cs2013/lab03/f/06.zip
- http://10.129.4.1/cs2013/lab03/f/07.zip
- http://10.129.4.1/cs2013/lab03/f/08.zip
- http://10.129.4.1/cs2013/lab03/f/09.zip
- http://10.129.4.1/cs2013/lab03/f/10.zip
- http://10.129.4.1/cs2013/lab03/f/11.zip
- http://10.129.4.1/cs2013/lab03/f/12.zip
- http://10.129.4.1/cs2013/lab03/f/13.zip
- http://10.129.4.1/cs2013/lab03/f/14.zip

Each zip file is a compressed form of a text file with the same name as the zip.
For instance, 04.zip is just 04.txt compressed.

Create a directory named `data/` in `lab03` folder. Extract each of these zip
file in the directory `data/`. Verify that the folder `data` contain the
files named `03.txt`, `04.txt` and so on till `14.txt`.
'
cd ../
rm -r data
mkdir data 
cd data
for i in {3..14}
do 
	wget -P data http://10.129.4.1/cs2013/lab03/f/"$1"
	unzip "$i.zip"
	rm "$i.zip"
done
cd ../





