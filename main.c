// Set <main.c>
// EE 312 Quiz 2 submission by
// John Wright
// jaw6527
// Slip days used: <0>
// Spring 2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


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

void testSubsetSum(){
    int array[5] = {1,2,3,4,5};
    assert(1==subsetSum(array,5,3,10));
    int array2[10] = {9,8,7,6,5,4,3,2,1,0};
    assert(1==subsetSum(array2,10,2,10));
    int array3[0] = {};
    assert(0==subsetSum(array3,0,2,10));

    int universal[100];
    for(int i = 0;i<100;i++)
        universal[i] = i;
    assert(!subsetSum(universal,100,0,2));
    assert(!subsetSum(universal,100,0,1));
    assert(subsetSum(universal,100,2,2));
    assert(subsetSum(universal,100,10,50));
    assert(subsetSum(universal,100,2,80));
    assert(subsetSum(universal,100,1,2));
    assert(!subsetSum(universal,0,5,2));
    assert(subsetSum(universal,100,10,100));
    printf("All tests passed.\n");
}

int main() {
    testSubsetSum();
    return 0;
}
