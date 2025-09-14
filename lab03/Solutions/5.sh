# Create a folder `output/06/`.
# In the folder `output/06/`, create 1000 files with names:
# datalog-000.log, datalog-001.log, ..., datalog-999.log.
#
# Each file `datalog-i.log` should contain the value of i*4.2
# computed to the accuracy of 3 decimal places.

cd ../
mkdir -p output/06
rm output/06/*
cd output/06/

for i in {0..999}; do
    # Determine filename with leading zeros
    if [[ $i -lt 10 ]]; then
        filename="datalog-00$i.log"
    elif [[ $i -lt 100 ]]; then
        filename="datalog-0$i.log"
    else
        filename="datalog-$i.log"
    fi

    # Compute value with 3 decimal places
    value=$(awk -v n="$i" 'BEGIN { printf "%.3f\n", n*4.2 }')

    # Write the value to the file
    echo "$value" > "$filename"
done
