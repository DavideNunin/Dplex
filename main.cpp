#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;
#include "header.h"

int main(int argv, char** argchar){

    if(argv == 2){
        if(argchar[1][0]=='-' && argchar[1][1]){
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
    int r, c;
    char *file = "input.txt";
    matrix m = char_to_float_matrix(file);
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
    /*
    while(flag){
        cout<<"inserisci il numero di equazioni: ";
        cin >>m;
        cout<<endl<<"inserisci il numero di variabili decisionali: ";
        cin >>n;
        cout<<endl<<"e' problema con "<<m<<" vincoli in "<<n<<" variabili decisionali, e' corretto?(y/n)";
        cin>>c;
        switch(c){
            case 'y':
                flag=false;
            break;
            default:
            break;
        }
    }
    */
    return 0;
}
