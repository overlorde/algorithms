/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 11462 ( Age sort )
 * Solution Method: Quick Sort ( 2 Partition )
 */
#include<cstdio>
#include<iostream>
 
#define SIZE 2000002
 
static int A[SIZE];
 
void quicksort (int *a, register int n) {
    register int i, j, mid;
    if (n < 2) return;
 
    mid = a[n >> 1];
 
    for (i = 0, j = n - 1; ; i++, j--) {
        while (a[i] < mid)
            i++;
        while (mid < a[j])
            j--;
 
        if (i >= j) break;
        std::swap(a[i], a[j]);
    }
    quicksort(a, i);
    quicksort(a + i, n - i);
}
 
int main () {
    register unsigned n, i;
    while(scanf("%u", &n) && n){
        for(i = 0; i < n; ++i)
            scanf("%d", &A[i]);
 
        quicksort(A, n);
 
        for (i = 0; i < n; i++)
            printf("%d%s", A[i], i == n - 1 ? "\n" : " ");
 
    }
    return 0;
}