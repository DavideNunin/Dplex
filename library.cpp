#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void printA(int m,int n, int** A){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
