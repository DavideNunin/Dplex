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

//determina se una colonna è un versore

int is_col_in_base(tableau t, int c){
	
	int row=0;
	int cont0=0;
	int cont1=0;

	for(int i=1; i<t.rows; i++){
		if(t.tab[i][c] == 0) cont0++;
		if(t.tab[i][c] == 1){
			row = i;
			cont1++;
		}
	}

	if(cont1==1 && cont0==t.rows-2) return row;
	return 0;
}
bool alpha_in_base(tableau t, bool inbase[]){
    for(int i=0;i<t.cols-1;i++)inbase[i]=false;
    int bias = t.cols-t.rows-1;
    int versor;
    bool flag= false;
    for(int i=bias+1;i<t.cols-1;i++){
        versor=is_col_in_base(t,i);
        if(versor!=0){
            inbase[versor]=true;
            flag=true;
        }
    }
    return flag;
}

tableau get_rid_by_alphas(tableau t){
    int bias=t.cols-t.rows-1;   //ultima colonna delle x
    int donecol[bias+1];
    bool donerow[t.rows];
    int nx=bias+1;
    int versor=0;
    pivot p;
    for(int i=0;i<nx;i++) donecol[i]=false;
    bool inbase[t.rows];
    while(alpha_in_base(t,inbase)){


    for(int k=bias+1;k<t.cols-1;k++){
        versor=is_col_in_base(t,k);
        if(versor!=0){
            inbase[versor]=true;
        }
    }

    for(int i=0;i<t.rows;i++){
        cout<<inbase[i]<<" ";
    }


        for(int i=0;i<nx;i++){
            for(int j=1;j<t.rows;j++){
                p={j,i};
                if(inbase[j] && !donecol[i] && do_pivot(t,p)){
                    print_tableau(t);
                    cout<<endl;
                    donecol[i]=true;
                   inbase[j]=false; 
                   break;
                }
            }
        }
    }
    /*
    p={3,5};
    bool cazzo;
    cazzo=do_pivot(t,p);
    */
    cout<<endl;
    t=zeroize(t);
	return t;    
}

void delete_alphas(tableau t){
	double ** new_tab;
	new_rows = t.rows;
	new_cols = t.cols - t.rows + 1;
	new_tab = double*[new_rows];
	for(int i=0; i<new_rows; i++){
		new_tab[i] = new double[new_cols];
		for(int j=0; j<new_cols; j++)
			new_tab[i][j] = t.tab[i][j];
	}
	t.tab = new_tab;
	t.rows = new_rows;
	t.cols = new_cols;
}

void restore_fo(tableau t, problem p){
	for(int i=0; i<t.cols-1, i++)
			t.tab[0][i] = p.f[i];
}

void restore_canonic(tableau t){
	for(int i=0; i<t.cols-1; i++){
		if(int j = is_col_in_base(t,i)){
			pivot p = {j,i};
			bool tmp = do_pivot(t,p);
		}
	}
}
