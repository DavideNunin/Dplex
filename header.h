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
void get_b(float* b, int r);
void get_f(float* f, int c);
void get_A(float** A,int r,int c);
