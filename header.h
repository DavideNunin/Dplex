//aggiungere 1 o -1 se il problema è di massimo o di minimo
struct problem{
    float ** A;
    int rows;
    int cols;
    float *b;
    float *f;
};

//aggiungere 1 o -1 se il problema è di massimo o di minimo
struct tableau{
    float **tab;
    int rows;
    int cols;
};

struct pivot{
	int r;
	int c;
}

int withparam(int argv, char** argchar);

void print_problem(problem m);

void pivot(problem m, pivot p);

float solve(problem m);
