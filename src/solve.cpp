#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
#include"header.h"
void solve(problem p){
tableau t= prob_to_tab(p);
print_tableau(t);
t=make_aux_prob(t);
print_tableau(t);
t=canonize(t);
print_tableau(t);
t=get_rid_by_alphas(t);
print_tableau(t);
}
