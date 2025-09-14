# For the file `data/05.txt`, an HTML file with some URLs appearing in it, do the following:
#
# * Ignore the initial and end HTML header part of the file.
# * Create a CSV file with URLs entered in the following format with headers:
#       year,quarter,fname,url
# * Your final file should be saved as `output/05.csv`.
#
# At the end, doing a `cat output/05.csv` should look like this:
#
# year,quarter,fname,url
# 2003,Qtr1,log20030101.zip,www.sec.gov/dera/data/Public-EDGAR-log-file-data/2003/Qtr1/log20030101.zip
# 2003,Qtr2,log20030401.zip,www.sec.gov/dera/data/Public-EDGAR-log-file-data/2003/Qtr2/log20030401.zip
# 2003,Qtr1,log20030103.zip,www.sec.gov/dera/data/Public-EDGAR-log-file-data/2003/Qtr1/log20030103.zip
#
# ... and the remaining entries
#
# Make sure that the output file has a .csv extension.

cd ../
echo "year,quarter,fname,url" > output/05.csv
grep "www.sec.gov/dera/data/Public-EDGAR-log-file-data/2003"  data/05.txt | awk -F'/' '{print $5","$6","$7","$0}'  >> output/05.csv

