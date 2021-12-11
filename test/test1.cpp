#include "../src/header.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;
fstream file;

void test_phase_1(){
	file.open("test.txt",ios::in);
    int c,r;
    file>>r;
    file>>c;

    double **A;
    double *b;
    double *f;
    
	f = new double[c];
    b = new double[r];
    A = new double*[r];
    
	for(int i=0;i<c;i++){
        file>>f[i];
    }
    
	for(int i=0;i<r;i++){
        A[i]=new double[c];
        for(int j=0;j<c;j++){
            file>>A[i][j];
        }
        file>>b[i];
    }
    
	problem p = {1,A, r, c, b, f};
	print_problem(p);
	tableau t = prob_to_tab(p);
	print_tableau(t);
    t=make_aux_prob(t);
    print_tableau(t);
    t=canonize(t);
    print_tableau(t);
    t=get_rid_by_alphas(t);
	print_tableau(t);

}

int main(){
	test_phase_1();
}
