#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include <iomanip>
#include "header.h"


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

bool is_cell_valid(int r, int c, int rmax, int cmax){
    return r >= 0 and c >= 0 and r < rmax and c < cmax;
}


void pivot(problem m, int r, int c){
       //print_problem(m);
       if (!is_cell_valid(r,c, m.rows, m.cols) || m.A[r][c] == 0)
           cout<<"Cella non valida per l'operazione di pivot";
       else{
	   float coeff = m.A[r][c];
           for(int i=0; i<m.cols; i++)
                m.A[r][i] /=  coeff;
	   for(int i=0; i<m.rows; i++){
	       float coeff = m.A[i][c];
               if(i == r) continue;
               for(int j=0; j<m.cols; j++)
                  m.A[i][j] -= coeff * m.A[r][j];
           }
           cout<<"Operazione di pivot completata sulla cella ("<<r<<","<<c<<")\n";
           print_problem(m);
        }   
}
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
