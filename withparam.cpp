#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
#include"header.h"
fstream in,out;


int withparam(int argv, char** argchar){
    in.open(argchar[1],ios::in);
    int n,m;
    in>>m;
    in>>n;
    int **A;
    int *b;
    b = new int[m];
    A = new int*[m];
    for(int i=0;i<m;i++){
        A[i]=new int[n];
        for(int j=0;j<n;j++){
            in>>A[i][j];
        }
        in >>b[i];
    }
    printA(m,n,A);
    return 0;
}

matrix char_to_float_matrix(char * file){
    in.open(file,ios::in);
    int r,c;
    in>>r>>c;
    cout<<r<<endl<<c<<endl;
    
    float **A;
    float *b;
    
    b = new float[r];
    A = new float *[r];
    
    for(int i=0;i<r;i++){
        A[i] = new float[c];
        for(int j=0;j<c;j++){
            in>>A[i][j];
            //cout<<"riga "<<i<<" colonna "<<j<<" ==> "<<A[i][j]<<"\n";
        }
        in>>b[i];
    }
    
    matrix m = {A, r, c};
    return m;
}
