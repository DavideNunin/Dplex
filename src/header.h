//aggiungere 1 o -1 se il problema è di massimo o di minimo
struct problem{
    int dir;
    double ** A;
    int rows;
    int cols;
    double *b;
    double *f;
};

struct tableau{
    double **tab;
    int rows;
    int cols;
};

struct pivot{
	int r;
	int c;
};

int withparam(int argv, char** argchar);
void solve(problem m);
void get_b(double* b, int r);
void get_f(double* f, int c);
void get_A(double** A,int r,int c);


//library.cpp

void print_problem(problem m);
void print_tableau(tableau t);
bool do_pivot(tableau m, pivot p);
tableau prob_to_tab(problem p);
void zeroize(tableau t);

//phase1.cpp
void canonize(tableau t);
tableau make_aux_prob(tableau t);
void get_rid_by_alphas(tableau t);
tableau delete_alphas(tableau t);
void restore_fo(tableau t, problem p);
void restore_canonic(tableau t);
tableau phase1(tableau t, problem p);

//phase2.cpp
tableau phase2(tableau t, int dir);

//test1.cpp
void test_phase1();
