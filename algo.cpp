#include <stdio.h> 
#include <fstream>
#include <iostream>
#include <vector>
#include "algo.h"
#include <algorithm>
#include <math.h>

using namespace std;
//Functie care calculeaza (a^n)%p, fara a face ridicarea la putere
long long modEficient(long long a, long long n, long long p) 
{   long rezultat;
    rezultat = 1; 
    a = a % p; 
  
    while (n > 0) 
    {  
        if (n % 2 == 1) 
            rezultat = (rezultat*a) % p; 
   
        n = n/2; 
        a = (a*a) % p; 
    } 
    return rezultat; 
} 

bool fermat( long long n, int iteratie) {
    int aux;
    long long a;
    srand((unsigned)time(0));
    
    aux = iteratie;

    //Cazurile speciale
    if( n == 2 || n == 3) {
        return true;
    }
    if( n == 1 || n == 0 || n == 4 || n < 1) {
        return false;
    }
    //Repetam de aux ori
    while (aux > 0) {
        //Alegem un a intre 2 si n-2
        a = (rand() % (n - 4)) + 2;
        
        //Calculam cel mai mare divizor comun intre a si n
        //Daca exista unul diferit de 1, inseamna ca n se divide cu a, deci
        //n nu este prim.
        if (__gcd(a, n) != 1) {
            return false;
        }
        //Daca a^(n-1) mod n este diferit de 1, inseamna ca n nu este prim
        if ( modEficient(a, n - 1, n) != 1) {
            return false;
        }
        //Se repeta programul de mai sus pentru a avea o siguranta mai mare ca
        //numarul este prim.
        aux--;
    }
    return true;
}
