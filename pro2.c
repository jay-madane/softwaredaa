#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void fillArray_bestCase(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
}

void fillArray_worstCase(int arr[], int n){
    int j = n;
    for(int i=0; i<n; i++){
        arr[i] = j;
        j--;
    }
}

void fillArray_avgCase(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = rand()%n;
    }
}

double bestCase_mergeSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_bestCase(arr,size);
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double worstCase_mergeSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_worstCase(arr,size);
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double avgCase_mergeSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_avgCase(arr,size);
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main(){
    int size;
    printf("\nAnalysis of Merge Sort Algorithm\n");
    size = 10;
    printf("\nArray with size 10:\n");
    printf("Time taken for best case: %f\n",bestCase_mergeSort(size));
    printf("Time taken for worst case: %f\n",worstCase_mergeSort(size));
    printf("Time taken for avg case: %f\n",avgCase_mergeSort(size));
    
    size = 100;
    printf("\nArray with size 100:\n");
    printf("Time taken for best case: %f\n",bestCase_mergeSort(size));
    printf("Time taken for worst case: %f\n",worstCase_mergeSort(size));
    printf("Time taken for avg case: %f\n",avgCase_mergeSort(size));
    
    size = 1000;
    printf("\nArray with size 1000:\n");
    printf("Time taken for best case: %f\n",bestCase_mergeSort(size));
    printf("Time taken for worst case: %f\n",worstCase_mergeSort(size));
    printf("Time taken for avg case: %f\n",avgCase_mergeSort(size));
    
    return 0;
}