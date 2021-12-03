#include "../src/header.h"
void test_phase_1(){
	double A[5][7] = {{ 1, 3, 0, 0, 0, 0, 0},
				  { 6,10, 1, 0, 0, 0, 30},
				  { 3, 2, 0,-1, 0, 0, 6},
				  {-1, 2, 0, 0, 1, 0, 1},
				  { 0, 1, 0, 0, 0,-1, 0.5}};
	double **tab;
	tab = new double*[5];
	
	for(int i=0; i<5; i++){
		tab[i] = new double[7];
		for(int j=0;j<7;j++)
			tab[i][j] = A[i][j];
	}
	tableau t = {tab, 5, 7};
	print_tableau(t);
    t=make_aux_prob(t);
    print_tableau(t);
    t=canonize(t);
    print_tableau(t);
    t=get_rid_by_alphas(t);
	print_tableau(t);

}

int main(){
	test_phase_1();
}
