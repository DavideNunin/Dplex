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

int withparam(int, char**);
void solve(problem);
void get_b(double*, int);
void get_f(double*, int);
void get_A(double**,int,int);


//library.cpp

//io
void print_problem(problem);
void print_tableau(tableau);
problem read_prob_from_file(char []);

//utils
bool do_pivot(tableau, pivot);
tableau prob_to_tab(problem);
void zeroize(tableau);

//phase1.cpp
bool is_prob_empty(tableau);
tableau phase1(tableau, problem);

//phase2.cpp
bool is_prob_unbounded(tableau, int);
tableau phase2(tableau, int);

//test1.cpp
void test_phase1();
