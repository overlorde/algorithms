// Program to find minimum cost for pyramid
//from given array

#include <iostream>

using namespace std;

#define ull unsigned long long;

// Returns min cost to form a pyramid

ull miniPyramidCost(ull arr[],ull N){

	// Store the max possible pyramid height

	ull *left = new ull[N];
	ull *right = new ull[N];

	// Max height at start is 1
:wq

	left[0] = min(arr[0],(ull)1);

	// For each position calculate max height

	for(int i = 1; i< N ; ++i){
		left[i] = min(arr[i],min(left[i-1]+1))
	}
}
