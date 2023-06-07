#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

double bestCase_quickSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_bestCase(arr,size);
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double worstCase_quickSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_worstCase(arr,size);
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double avgCase_quickSort(int n){
    int size = n;
    int arr[size];
    clock_t start, end;
    double cpu_time_used;
   
    fillArray_avgCase(arr,size);
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main(){
    int size;
    printf("\nAnalysis of Quick Sort Algorithm\n");
    size = 10;
    printf("\nArray with size 10:\n");
    printf("Time taken for best case: %f\n",bestCase_quickSort(size));
    printf("Time taken for worst case: %f\n",worstCase_quickSort(size));
    printf("Time taken for avg case: %f\n",avgCase_quickSort(size));
    
    size = 100;
    printf("\nArray with size 100:\n");
    printf("Time taken for best case: %f\n",bestCase_quickSort(size));
    printf("Time taken for worst case: %f\n",worstCase_quickSort(size));
    printf("Time taken for avg case: %f\n",avgCase_quickSort(size));
    
    size = 1000;
    printf("\nArray with size 1000:\n");
    printf("Time taken for best case: %f\n",bestCase_quickSort(size));
    printf("Time taken for worst case: %f\n",worstCase_quickSort(size));
    printf("Time taken for avg case: %f\n",avgCase_quickSort(size));
    
    return 0;
}