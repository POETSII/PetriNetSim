#!/bin/bash
out=~/out_cpu.txt

#rm -f $out
#rm -f $stats
#mkdir $res

echo_all () {
	echo $1
	echo $1 >> $out
}

for (( f=1000; f<=24000; f=f+1000 ))
do
	echo_all "Next: $f"
	date
	let n=f*50
	./pnsim $n 100 >> $out
done
