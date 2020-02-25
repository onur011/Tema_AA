#include <stdio.h> 
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //Vector cu pseudoprime
    int pseudoprime[] ={341,561,645,1105,1387,1729,1905,
    2047,2465,2701,2821,3277,4033,4369,4371,4681,5461,6601,
    7957,8321,8481,8911,10261,10585,11305,12801,13741,13747,
    13981,14491,15709,15841,16705,18705,18721,19951,23001,23377,
    25761,29341};
    int j, n = 0, Q, random,randomIteration, k, nrTeste = 0;
    unsigned int i;
    bool ok;
    srand((unsigned)time(0));
    ifstream inputFile("prime");  
    vector<long> prime,compuse,vector,ref;
    long long value;

    //Se creaza un vector cu numerele prime din fisierul "prime".         
    while ( inputFile >> value ) {
        prime.push_back(value);
    }
    
    inputFile.close();

    
    //Generator care creaza 9592 de numere compuse.
    //Acesta compara cu vectorul de numere prime, si cu cele pseudoprime
    //Daca nu se afla printre acestea, il adaugam la vectorul de compuse
    k = (rand()%70000)+1;
    while(n != 9592){   
        ok = true;

        for( j = 0; j < 9592; j++) {
            if( k == prime[j])
                ok = false;
            for(int l = 0; l < 40; l++) {
                if( k == pseudoprime[l])
                    ok = false;
            }
        }

        if( ok == true) {
            compuse.push_back(k);
            n++;
        }
        k++;
    }
    //Se creaza 25 de teste
    while( nrTeste < 25) {
        ref.clear();
        vector.clear();
    //Se alege la intamplare lungimea vectorului de intrare, care urmeaza sa fie creat. 
        Q = (rand()%9592)+1;
    //Se face un vector cu element din prime si compuse;
        for( j = 0; j < Q; j++){
            
            if (nrTeste < 15) {
                
                random = (rand()%10)+1;
                randomIteration = (rand()%9592)+1;
                if( random > 5) {
                    
                    vector.push_back(prime[randomIteration]);
                    ref.push_back(prime[randomIteration]);
                } else {
                    
                    vector.push_back(compuse[randomIteration]);
                }
            } else {
            //Pentru testele de la 15 la 24, acesta contin si pseudoprime
                random = (rand()%11)+1;
                randomIteration = (rand()%9592)+1;
                if( random < 6) {
                    
                    vector.push_back(prime[randomIteration]);
                    ref.push_back(prime[randomIteration]);
                } else if (random > 5 && random < 11) {
                    
                    vector.push_back(compuse[randomIteration]);
                } else if (random == 11){
                    
                    int randomPseudoprime = (rand()%40);
                    vector.push_back(pseudoprime[randomPseudoprime]);
                }
            }

        }
        //Se scrie setul de intrare in fisierul "in"
        ofstream in("in/test" + to_string(nrTeste) + ".in");

        in << vector.size() << endl;
        for( i = 0; i < vector.size(); i++) {
            in << vector[i] << " ";
        }
        in.close();

        //In unele cazuri, se intampla ca in vectorul de verificare sa apara
        //valori de 0, care trebuie eliminate
        ofstream refout("out/test" + to_string(nrTeste) + ".out");
        for( i = 0; i < ref.size(); i++) {
            if( ref[i] == 0)
                ref.erase(ref.begin() + i);
        }
        //Se scrie setul de verificare in fisierul "out"
        refout << ref.size() << endl;
        for( i = 0; i < ref.size(); i++) {
            refout << ref[i] << " ";
        }
        refout.close();
        nrTeste++;
    }
}