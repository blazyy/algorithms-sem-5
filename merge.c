#include <stdio.h>
#include<time.h>
//merge sort

void printArray(int arr[], int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
}

void mergeSort(int arr[], int size){
    
    //functions returns if there's only one element in array
    if(size < 2)
        return;
        
    int i, j = 0, mid, *l, *r, lsize, rsize;
    
    mid = size/2;
    lsize = mid;
    rsize = size-mid;
    
    l = (int *)malloc(lsize * sizeof(int));
    r = (int *)malloc(rsize * sizeof(int));
    
    //filling left subarray
    for(i=0; i<mid; i++)
        l[i] = arr[i];
        
    //filling right subarray
    for(i=mid; i<size; i++)
        r[j++] = arr[i];
        
    mergeSort(l, lsize);
    mergeSort(r, rsize);
    merge(arr, l, lsize, r, rsize);
    
    free(l);
    free(r);
}

void merge(int arr[], int l[], int lsize, int r[], int rsize){
    
    int i, j, k;
    i = j = k = 0;
    
    while(i<lsize && j<rsize){
        
        if(l[i] <= r[j])
            arr[k++] = l[i++];
            
        else
            arr[k++] = r[j++];
    }
    
    while(i < lsize)
        arr[k++] = l[i++];
    
    while(j < rsize)
        arr[k++] = r[j++];
    
}

int main()
{
    int i, randnum, size = 20;
    int arr[size];
    clock_t start, end;
    double time_elapsed;
    
    //fills array with random numbers
    for(i=0; i<size; i++){
        randnum = rand() % 100;
        arr[i] = randnum;
    }
    
    printf("\nBefore sorting: ");
    printArray(arr, size);
    
    start = clock();
    mergeSort(arr, size);
    end = clock();
    
    printf("\nAfter sorting: ");
    printArray(arr, size);
    
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nElapsed time: %fs", time_elapsed);

    return 0;
}

