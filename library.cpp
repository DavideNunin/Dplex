#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include <iomanip>
#include "header.h"

//da stampare anche se il problema è di massimo o di minimo
void print_problem(problem m){
    cout<<"Matrice\n";
    cout<<"z = ";
    for(int i=0;i<m.cols;i++){
        cout<<setw(8)<<m.f[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            cout<<setw(8)<<m.A[i][j]<<" ";
        }
        cout<<"   =   "<<m.b[i];
        cout<<endl;
    }
    cout<<endl;
}

//controlla se una cella è valida per fare pivot
bool is_cell_valid(pivot p, tableau m){
    return p.r > 0 && p.c >= 0 && p.r < m.rows && p.c < m.cols-1 && m.A[r][c] != 0;
}

//esegue il pivot su una cella del tableau

void pivot(tableau m, pivot p){
       if (!is_cell_valid(p,m) )
           cout<<"Cella non valida per l'operazione di pivot";
       else{
	   float coeff = m.A[p.r][p.c];
           for(int i=0; i<m.cols; i++)
                m.A[p.r][i] /=  coeff;
	   for(int i=0; i<m.rows; i++){
	       float coeff = m.A[i][p.c];
               if(i == p.r) continue;
               for(int j=0; j<m.cols; j++)
                  m.A[i][j] -= coeff * m.A[p.r][j];
	 }
           cout<<"Operazione di pivot completata sulla cella ("<<p.r<<","<<p.c<<")\n";
        }   
}

tableau prob_to_tab(problem p){

	float M[p.rows+1][p.cols+1];
	
	for(int i=0; i < p.cols; i++)
		M[0][i] = p.f[i];
	
	for(int i=1; i <= p.rows; i++)
		M[i][p.cols] = p.b[i];

	for(int i=1; i <= p.rows; i++){
		for(int j=0; j < p.cols; j++)
			M[i][j] = p.A[i-1][j];	
	}

	//valore funzione obiettivo
	
	tableau t = {M, p.rows+1, p.cols+1};
	return t;
}

/*
//non è detto che serva
problem tab_to_prob(tableau t){
	
	float A[t.rows-1][t.cols-1];
	float b[t.rows-1];
	float f[t.cols-1];
	
	for(int i=0; i < t.cols-1; i++)
		f[i] = t.tab[0][i];
	
	for(int i=1; i < t.rows; i++)
		b[i] = t.tab[i][t.cols-1];

	for(int i=1; i < t.rows; i++){
		for(int j=0; j < t.cols-1; j++)
			A[i-1][j] = M[i][j];	
	}

	//valore funzione obiettivo
	
	problem p = {A, t.rows-1, t.cols-1, b, f};
	return p;
}
*/

float solve(problem m){
    //phase1()
    int r,c;
    r=m.rows;
    c=m.cols;
    float **A2;
    float *b;
    float *f;
    f = new float[r+c];
    b = m.b;
    return 1;
}
void get_b(float* b,int r){
    cout<<"inserisci il vettore b:"<<endl;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<r;i++){
            cin>>b[i];
        }
        for(int i=0;i<r;i++){
            if(b[i]<0){
                flag=true;
                cout<<endl<<"a maledettooo inserisci un vettore b con componenti maggiori di 0"<<endl;
            }
        }
    }
}

void get_f(float* f,int c){
    cout<<"inserisci il vettore f:"<<endl;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<c;i++){
            cin>>f[i];
        }
        for(int i=0;i<c;i++){
            if(f[i]<0){
                flag=true;
                cout<<endl<<"a maledettooo inserisci un vettore f con componenti maggiori di 0"<<endl;
            }
        }
    }
}
void get_A(float** A,int r,int c){
    bool flag=true;
    for(int i=0;i<r;i++){
        A[i]= new float[c];
    }
    while(flag){
        flag=false;
        for(int i=0;i<r;i++){
            cout<<"inserisci la riga "<<i<<" di A"<<endl;
            for(int j=0;j<c;j++){
                cin>>A[i][j];
            }
        }
    }
}
