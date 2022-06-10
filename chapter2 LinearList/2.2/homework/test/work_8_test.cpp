#include <stdio.h>
#include <stdlib.h>

void Reverse(int A[], int from, int to, int arraySize) {
    for (int i = 0; i < arraySize/2; i++) {
        int temp = A[from + i];
        A[from + i] = A[to - i];
        A[to - i] = A[from + i];
    }
}

void Converse(int A[], int from, int to, int arraySize){

    
}


