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
    double **A;
    double *b;
    double *f;
    f = new double[c];
    b = new double[r];
    A = new double*[r];
    for(int i=0;i<r;i++){
        A[i]=new double[c];
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
