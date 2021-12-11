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
    
	cout<<"Problema ausiliario\n";
	t=make_aux_prob(t);
    print_tableau(t);

	cout<<"Problema ausiliario in forma canonica\n";
    canonize(t);
    print_tableau(t);
	
	cout<<"Problema ausiliario con uscita di variabili artificiali\n";
    get_rid_by_alphas(t);
	print_tableau(t);
	
	cout<<"Problema senza variabili artificiali\n";
	t = delete_alphas(t);
	print_tableau(t);
	
	cout<<"Problema con funzione obiettivo ripristinata\n";
	restore_fo(t,p);
	print_tableau(t);

	cout<<"Problema originale in forma canonica\n";
	restore_canonic(t);
	print_tableau(t);


}

int main(){
	test_phase_1();
}
