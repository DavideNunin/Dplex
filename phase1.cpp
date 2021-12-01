#include "header.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


//vede se il problema è compatibile
bool is_prob_comp(tableau t){
	
}

//mette il tableau in forma canonica

tableau canonize(tableau t){
	//fare pivot sui versori
}


//crea il tableau del problema ausiliario

tableau make_aux_prob(tableau t){
	
	rows_aux = t.rows;
	cols_aux = t.cols + t.rows;
	
	float tab_aux[rows_aux][cols_aux];

	for(int i=0; i < t.cols - 1; i++)
		tab_aux[0][i] = 0;
	
	for(int i=t.cols-1;i<cols_aux-1;i++)
		tab_aux[0][i] = 1;

	tab_aux[0][cols_aux-1] = 0;
	
	for(int i=1; i < row_aux; i++)
		tab_aux[i][cols_aux-1] = t.tab[i][t.cols-1];

	for(int i=1; i < row_aux; i++){
		int j=0;
		for(;j<t.cols-1; j++)
			tab_aux[i][j] = t.tab[i][j];
		for(;j<row_aux-1;j++)
			tab_aux[i][j] = float( (j - t.cols) == i );
	}
	tableau aux_prob = {tab_aux, rows_aux, cols_aux};
	return canonize(tab_aux, t.cols);
}

int main(){
	
}
