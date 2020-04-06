#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

int subsetSum(int arr[], int n, int k, int v){
    if(v==0&&k==0) return true;
    if(v!=0&&k==0) return false;
    if(n==0) return false;

    int temp1 = 0;
    if(v >= arr[0]){
        temp1 = subsetSum(arr + 1, n - 1, k - 1, v - arr[0]);
    }

    int temp2 = subsetSum(arr + 1, n - 1, k, v);
    return temp1 + temp2 > 0;
}

int main() {
    int array[N] = {1,2,3,4,5};
    printf("Result: %d", subsetSum(array,N,3,10));
    return 0;
}
