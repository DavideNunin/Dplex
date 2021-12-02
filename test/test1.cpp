#include "../header.h"
void test_phase_1(){
	float A[5][7] = {{ 1, 3, 0, 0, 0, 0, 0},
				  { 6,10, 1, 0, 0, 0, 30},
				  { 3, 2, 0,-1, 0, 0, 6},
				  {-1, 2, 0, 0, 1, 0, 1},
				  { 0, 1, 0, 0, 0,-1, 0.5}};
	float **tab;
	tab = new float*[5];
	
	for(int i=0; i<5; i++){
		tab[i] = new float[7];
		for(int j=0;j<7;j++)
			tab[i][j] = A[i][j];
	}
	tableau t = {tab, 5, 7};
	print_tableau(t);
	print_tableau(make_aux_prob(t));
}

int main(){
	test_phase_1();
}
