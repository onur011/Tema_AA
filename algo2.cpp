#include <stdio.h> 
#include <fstream>
#include <iostream>
#include <vector>
#include "algo.h"
#include <algorithm>
#include <math.h>

using namespace std;

bool millerRabin(long long n, int iteratie) {
    long long a, b;
    long long j;
    bool prim;
    int aux;
    long long r, d;
    srand((unsigned)time(0));

    aux = iteratie;

    //Cazuri speciale
    if( n == 1 || n == 4 || n < 1) {
        return false;
    }
    if( n == 2 || n == 3 || n == 5) {
        return true;
    }
    
    //Daca n este impar, il scriem sub forma n - 1 = d*2^r;
    if( n % 2 == 1 && n != 1 && n != 3){
        d = n - 1;
        r = 0;
            
        while (d % 2 == 0) {
        r++;
        d = d/2;
        }   
    } else {
    //Daca n este par, inseamna ca nu e prim
        return false;
    }
    //Repetam de aux ori
    while (aux > 0) {
        prim = false;
        //Alegem un a intre 2 si n-2
        a = (rand() % (n - 4)) + 2;
        
        // b este (a^d) mod n;
        b = modEficient(a, d, n);
        
        //Daca b este 1 sau n-1 inseamna ca nr este prim
        if ( b == 1 || b == n - 1) {
            aux--;
            prim = true;
            continue;
        }
        //Daca b nu este 1 sau n-1.
        for (j = 0; j < r; j++) {
            //Noul b este (b^2)%n
            b = modEficient(b, 2, n);
            //Daca b este 1 inseamna ca n este compus
            if (b == 1){
                return false;
            }

            //Daca b este n - 1, inseamna ca n este prim, dar repetam programul
            //de aux ori pentru a avea o siguranta mai mare.
            if (b == n - 1) {
                prim = true;
                break;
            } 
        }

        if(prim == false)
            return false;
        
        aux--;
    }
    return true;
}