struct problem{
    float ** A;
    int rows;
    int cols;
    float *b;
    float *f;
};
struct tableau{
    float **tab;
    int rows;
    int cols;
};
int withparam(int argv, char** argchar);
void print_problem(problem m);
void pivot(problem m, int r, int c);
float solve(problem m);
