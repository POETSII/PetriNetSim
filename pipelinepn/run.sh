#!/bin/bash
out=~/out.txt
stats=~/out_stats.txt

#rm -f $out
#rm -f $stats
#mkdir $res

echo_all () {
	echo $1
	echo $1 >> $out
	echo $1 >> $stats
}

cd build

for (( f=500; f<=24000; f=f+500 ))
do
	echo_all "Next: $f"
	date
	./run $f 100 >> $out
	../../util/sumstats.awk stats.txt >> $stats
	sleep 10s
done

cd ..
