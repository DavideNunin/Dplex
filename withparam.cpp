#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
#include"header.h"
fstream in,out;


int withparam(int argv, char** argchar){
    in.open(argchar[1],ios::in);
    int c,r;
    in>>r;
    in>>c;
    float **A;
    float *b;
    float *f;
    f = new float[c];
    b = new float[r];
    A = new float*[r];
    for(int i=0;i<r;i++){
        A[i]=new float[c];
        for(int j=0;j<c;j++){
            in>>A[i][j];
        }
        in >>b[i];
    }
    problem m = {A, r, c, b, f};
    print_problem(m);
    //cout<<solve(m);
    return 0;
}
