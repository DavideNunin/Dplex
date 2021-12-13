#include "../src/header.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void test_phase_1(){
	problem p = read_prob_from_file("../test1.txt");
	solve(p);
}

int main(){
	test_phase_1();
}
