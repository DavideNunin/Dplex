#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include <iomanip>
#include "header.h"

void printA(int m,int n, int** A){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print_matrix(matrix m){
    cout<<"Matrice\n";
    for(int i=0;i<m.rows;i++){
        for(int j=0;j<m.cols;j++){
            cout<<setw(10)<<m.A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool is_cell_valid(int r, int c, int rmax, int cmax){
    return r >= 0 and c >= 0 and r < rmax and c < cmax;
}


void pivot(matrix m, int r, int c){
       //print_matrix(m);
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
           print_matrix(m);
        }   
}
