#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
#include"header.h"

void solve(problem p){
	tableau t1 = prob_to_tab(p);
	print_tableau(t1);
	tableau t2 = make_aux_prob(t1);
	print_tableau(t2);
	canonize(t2);
	print_tableau(t2);
	get_rid_by_alphas(t2);
	print_tableau(t2);
}
