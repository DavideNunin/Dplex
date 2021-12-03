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
        cout<<setw(12)<<m.f[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            cout<<setw(12)<<m.A[i][j]<<" ";
        }
        cout<<"   =   "<<m.b[i];
        cout<<endl;
    }
    cout<<endl;
}
tableau zeroize(tableau t){
    for(int i=0;i<t.rows;i++){
        for(int j=0;j<t.cols;j++){
            if(t.tab[i][j]<0.00000000000001 && t.tab[i][j]>-0.00000000000001)
                t.tab[i][j]=0;
        }
    }
    return t;
}

void print_tableau(tableau t){
	cout<<"Tableau:\n";
	cout<<t.rows<<" x "<<t.cols<<"\n";
	for(int i=0; i<t.rows; i++){
		for(int j=0;j<t.cols;j++)
			cout<<setw(12)<<t.tab[i][j];
		cout<<"\n";
	}
	cout<<"\n";
}


//controlla se una cella è valida per fare pivot
bool is_cell_valid(pivot p, tableau m){
    return p.r > 0 && p.c >= 0 && p.r < m.rows && p.c < m.cols-1 && m.tab[p.r][p.c] != 0;
}

//esegue il pivot su una cella del tableau

bool do_pivot(tableau m, pivot p){
       if (!is_cell_valid(p,m) ){
           cout<<"Cella non valida per l'operazione di pivot "<<p.r<<" "<<p.c<<endl;
           return false;
       }
       else{
	   double coeff = m.tab[p.r][p.c];
           for(int i=0; i<m.cols; i++)
                m.tab[p.r][i] /=  coeff;
	   for(int i=0; i<m.rows; i++){
	       double coeff = m.tab[i][p.c];
               if(i == p.r) continue;
               for(int j=0; j<m.cols; j++)
                  m.tab[i][j] -= coeff * m.tab[p.r][j];
	 }
           cout<<"Operazione di pivot completata sulla cella ("<<p.r<<","<<p.c<<")\n";
           return true;
        }   
}

tableau prob_to_tab(problem p){

	double **M;
	M = new double *[p.rows+1];

	for(int i=0; i<p.rows+1; i++)
		M[i] = new double [p.cols+1];
	
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
	
	double A[t.rows-1][t.cols-1];
	double b[t.rows-1];
	double f[t.cols-1];
	
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

double solve(problem m){
    //phase1()
    int r,c;
    r=m.rows;
    c=m.cols;
    double **A2;
    double *b;
    double *f;
    f = new double[r+c];
    b = m.b;
    return 1;
}
void get_b(double* b,int r){
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

void get_f(double* f,int c){
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
void get_A(double** A,int r,int c){
    bool flag=true;
    for(int i=0;i<r;i++){
        A[i]= new double[c];
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
