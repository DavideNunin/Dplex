#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
#include "header.h"

int main(int argv, char** argchar){
	
    if(argv == 2){
        if(argchar[1][0]=='-' && argchar[1][1]=='h'){
            cout<<"Dplex è una cagata che prova a fare l' algoritmo del simplesso o qualcosa del genere, se si usa in modalità commandline bisogna seguire i comandi del prompt, altrimenti se si specifica un file di input basta formularlo correttamente secondo una logica che non ho voglia di scrivere"<<endl;
            return 0;
        }
        cout<<withparam(argv,argchar);
        return 0;
    }
    
    system("cat ../logo/logo");
    cout<<endl;
    
    bool flag=true;
    //int n,m;
    char o = 'n';
    int r = -1, c = -1;

    /*
    char *file = "input.txt";
    matrix m = char_to_double_matrix(file);
    while(flag){
	print_matrix(m);
        cout<<"inserisci la riga: ";
        cin >>r;
        cout<<endl<<"inserisci la colonna: ";
        cin >>c;
        pivot(m, r, c);
        cout<<endl<<"vuoi continuare(y/n)";
        cin>>o;
        flag = o == 'y' || o == 'Y';
    }
    */
	
    while(flag){
	r = c = -1;
        cout<<"inserisci il numero di equazioni: ";
        while(r<=0){
        cin >>r;
        }
        cout<<endl<<"inserisci il numero di variabili decisionali: ";
        while(c<=0)
        cin >>c;
        cout<<endl<<"e' problema con "<<r<<" vincoli in "<<c<<" variabili decisionali, e' corretto?(y/n)";
        cin>>o;
        switch(o){
            case 'y':
                flag=false;
            break;
            default:
            break;
        }
    }
    double **A;
    double *b;
    double *f;
    f = new double[c];
    b = new double[r];
    A = new double*[r];
    get_b(b,r);
    get_f(f,c);
    get_A(A,r,c);
    problem p={1,A,r,c,b,f};
    solve(p);
    return 0;
}
