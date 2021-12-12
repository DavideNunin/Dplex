#include "../src/header.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

void test_phase_1(){
	fstream in;
	in.open("../test1.txt",ios::in);
    
	int r,c;
    in>>r;
    in>>c;
	
    double **A;
    double *b;
    double *f;
    
	f = new double[c];
    b = new double[r];
    A = new double*[r];
    
	for(int i=0;i<c;i++)
        in>>f[i];
    
	for(int i=0;i<r;i++){
        A[i]=new double[c];
        for(int j=0;j<c;j++)
            in>>A[i][j];
        in>>b[i];
    }
    
	in.close();

	problem p = {1,A, r, c, b, f};
	print_problem(p);
	tableau t = prob_to_tab(p);
	print_tableau(t);
    t = phase1(t, p);
	cout<<"Eseguendo fase 2 su problema originale...\n";
	t = phase2(t,p.dir);
	cout<<"La soluzione ottima è "<<-t.tab[0][t.cols-1]<<"\n";
}

int main(){
	test_phase_1();
}
