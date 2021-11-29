struct matrix{
    float ** A;
    int rows;
    int cols;
};

int withparam(int argv, char** argchar);
void printA(int m,int n, int** A);
void print_matrix(matrix m);
void pivot(matrix m, int r, int c);
matrix char_to_float_matrix(char * file);
