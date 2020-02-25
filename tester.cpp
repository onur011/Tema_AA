#include <stdio.h> 
#include <fstream>
#include <iostream>
#include "algo.h"
#include <vector>
#include <chrono> 

using namespace std::chrono; 

using namespace std;


int main(int argc, char* argv[]) {
    (void)argc;
    int n, i, k;
    vector<long long> v,f,m;
    ifstream inputFile(argv[1]);
    long long aux;
    
    inputFile >> n;
    //Introducem numarul de iteratii ca parametru
    k = atoi(argv[2]);
    //Citim din fisierul de intrare si introducem elementele in v
    for (i = 0; i < n; i++) {
        inputFile >> aux;
        v.push_back(aux);
    }

    inputFile.close();
    auto startF = high_resolution_clock::now(); 
    //Apelam testul Fermat pentru fiecare element din v
    for( i = 0; i < n; i++) {
        if( fermat(v[i],k) == true) 
            f.push_back(v[i]);
    }
    auto stopF = high_resolution_clock::now();
    auto durationF = duration_cast<milliseconds>(stopF - startF);  
    cout <<"timp Fermat "<< durationF.count() << endl;  
    long long size = f.size();

    ofstream outFile("outF");
    
    outFile << size << endl;
    //Afisam numarul de elemente prime si elementele prime, conform testului
    //Fermat
    for( i = 0; i < size; i++)
        outFile<<f[i]<<" ";

    outFile.close();
    //Apelam testul Miller-Rabin pentru fiecare element din v
    auto startM = high_resolution_clock::now();
    for(i = 0; i < n; i++){
        if( millerRabin(v[i],k) == true) {
            m.push_back(v[i]);
        }
    }
    auto stopM = high_resolution_clock::now();
    auto durationM = duration_cast<milliseconds>(stopM - startM);  
    cout <<"timp Miller "<< durationM.count() << endl;  

    long long sizeM = m.size();
    ofstream outFileM("outM");
    
    outFileM << sizeM << endl;
    //Afisam numarul de elemente prime si elementele prime, conform testului
    //Miller-Rabin
    for( i = 0; i < sizeM; i++)
        outFileM<<m[i]<<" ";
    outFileM.close();

    return 0;
}