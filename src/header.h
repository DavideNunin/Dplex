//aggiungere 1 o -1 se il problema è di massimo o di minimo
struct problem{
    int dir;
    double ** A;
    int rows;
    int cols;
    double *b;
    double *f;
};

//aggiungere 1 o -1 se il problema è di massimo o di minimo
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

void print_problem(problem m);
void print_tableau(tableau t);

bool do_pivot(tableau m, pivot p);
tableau make_aux_prob(tableau t);


void solve(problem m);

void get_b(double* b, int r);
void get_f(double* f, int c);
void get_A(double** A,int r,int c);

void test_phase_1();
tableau canonize(tableau t);
tableau get_rid_by_alphas(tableau t);
tableau zeroize(tableau t);
tableau prob_to_tab(problem p);
