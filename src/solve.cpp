#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#include "header.h"

void solve(problem p){
	print_problem(p);
	tableau t = prob_to_tab(p);
	print_tableau(t);
    t = phase1(t, p);
	if (!is_prob_empty(t)){
		cout<<"Eseguendo fase 2 su problema originale...\n\n";
		t = phase2(t,p.dir);
		print_tableau(t);
		if(!is_prob_unbounded(t, p.dir))
			cout<<"La soluzione ottima è "<<-t.tab[0][t.cols-1]<<"\n";
	}
}
