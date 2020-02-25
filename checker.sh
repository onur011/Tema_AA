#!/bin/bash

varFermat=0
varMiller=0

echo Introduceti numarul de iteratii:;

read iteratii;

make clean;

make;

echo;
echo "============Fermat=========|=======Miller-Rabin========";
echo;

for i in {0..24}
do
    ./test in/test$i.in $iteratii;

    if diff "outF" "out/test$i.out" >/dev/null ;
    then
        fermat="OK  "
        varFermat=$((varFermat+1))
    else
        fermat="FAIL"
    fi

    if diff "outM" "out/test$i.out" >/dev/null ;
    then
        miller="OK  "
        varMiller=$((varMiller+1))
    else
        miller="FAIL"
    fi

    if [ $i -eq 15 ];
    then
        echo;
        echo "----------------------Pseudoprime----------------------";
        echo;
    fi

    if [ 10 -gt $i ];
    then
        echo "Test$i.in ............ $fermat | Test$i.in ............ $miller"; 
    else
        echo "Test$i.in ........... $fermat | Test$i.in ........... $miller";
    fi
done
    echo;
    echo "------Tests $varFermat/25 Fermat-------Tests $varMiller/25 Miller-Rabin--";
    echo;
    make clean