#!/bin/bash

#hard_links=$( find $1 -type f -links +$2 -printf "%f\n" )
amount_of_hard_links=1
files=$( find $1 -type f )

for f in $files
do
    command=$( stat $f | grep "Links" | cut -d ":" -f 4 )
    if [ $command -gt $amount_of_hard_links ]
    then
        amount_of_hard_links=$command
    fi
done

k=0
while [ $amount_of_hard_links -gt $k ]
do
    printf "$( find $1 -type f -links +$k -printf "%f\n" )\n"
    k=$((k+1))
done
