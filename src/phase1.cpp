#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;


#include"header.h"

/*
//vede se il problema è compatibile
bool is_prob_comp(tableau t){
	
}
*/

//mette il tableau in forma canonica

tableau canonize(tableau t){
    int bias=t.cols-t.rows-1;
    bool flag;
	for(int i=1; i<t.rows; i++){
		pivot p = {i,i+bias};
		flag=do_pivot(t,p);
	}
	return t;
}

//crea il tableau del problema ausiliario

tableau make_aux_prob(tableau t){
	
	int rows_aux = t.rows;
	int cols_aux = t.cols + t.rows-1;
	
	double **tab_aux;
	
	tab_aux = new double*[rows_aux];

	for(int i=0; i<rows_aux; i++)
			tab_aux[i] = new double[cols_aux];

	for(int i=0; i < t.cols - 1; i++)
		tab_aux[0][i] = 0;
	
	for(int i=t.cols-1;i<cols_aux-1;i++)
		tab_aux[0][i] = 1;

	tab_aux[0][cols_aux-1] = 0;
	
	for(int i=1; i < rows_aux; i++)
		tab_aux[i][cols_aux-1] = t.tab[i][t.cols-1];

	for(int i=1; i < rows_aux; i++){
		int j=0;
		for(;j<t.cols-1; j++)
			tab_aux[i][j] = t.tab[i][j];
		for(;j<cols_aux-1;j++)
			tab_aux[i][j] = double( (i + t.cols -2) == j );
	}
	tableau aux_prob = {tab_aux, rows_aux, cols_aux};
    return aux_prob;
}
tableau get_rid_by_alphas(tableau t){
    bool inbase[t.rows];
    for(int i=0;i<t.cols-1;i++)inbase[i]=false;
    int bias=t.cols-t.rows-1;   //ultima colonna delle x
    int donecol[bias+1];
    bool donerow[t.rows];
    int nx=bias+1;
    int versor=0;
    pivot p;
    /*
    for(int i=0;i<nx;i++) donecol[i]=false;
    for(int i=0;i<t.rows;i++)donerow[i]=false;
    for(int i=0;i<nx;i++){
        for(int j=1;j<t.rows;j++){
            p={j,i};
            if(!donerow[j] && !donecol[i] && do_pivot(t,p)){
                print_tableau(t);
                cout<<endl;
               donerow[j]=true; 
               donecol[i]=true;
            }
        }
    }
    */
    for(int k=bias+1;k<t.cols-1;k++){
        versor=is_col_in_base(t,k);
        if(versor!=0){
            inbase[versor]=true;
        }
    }
    for(int i=0;i<t.rows;i++){
        cout<<inbase[i]<<" ";
    }
    t=zeroize(t);
return t;    
}
