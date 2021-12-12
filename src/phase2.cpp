#include "header.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cfloat>
#include <unistd.h>

using namespace std;

bool is_sol_op(tableau t, int dir){
	bool flag = true;
	for(int i=0; i<t.cols-1; i++)
		flag = flag && t.tab[0][i] * dir <= 0;
	return flag;
}

bool is_prob_unbounded(tableau t, int dir){
	for(int i=0; i<t.cols-1; i++){
		bool flag = t.tab[0][i] * dir > 0;
		if(flag){
			for(int j=1; j<t.rows; j++)
				flag = flag && t.tab[j][i] <= 0; 
			if(flag) return true;
		}
	}
	return false;
}

pivot bland_rule(tableau t, int dir){
	
	pivot p = {0,0};

	for(int i=0; i<t.cols-1; i++){
		
		if(t.tab[0][i] * dir > 0){
			
			double min_rate = DBL_MAX;
			
			for(int j=1; j<t.rows; j++){
				double new_rate = min_rate;
				
				if(t.tab[j][i] > 0)
					new_rate = t.tab[j][t.cols-1]/ t.tab[j][i];
				
				if(new_rate < min_rate){
					min_rate = new_rate;
					p.r = j;
					p.c = i;
				}

			}

			return p;
		}
	}

	return p;
}

tableau phase2(tableau t, int dir){
	int cont = 0;
	while(!is_sol_op(t, dir)){
		
		if(is_prob_unbounded(t,dir)){
			cout<<"Il problema è illimitato\n";
			break;
		}
		
		pivot p = bland_rule(t, dir);
		bool flag = do_pivot(t,p);
		cout<<"Op. di pivot n°"<<++cont<<"\n";
		zeroize(t);
		print_tableau(t);
	}
	return t;
}
