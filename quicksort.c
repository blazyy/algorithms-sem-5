#include <stdio.h>

void printArray(int arr[], int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    
    int i;
    int pivot = arr[end];
    int pIndex = start;
    
    for(i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end){
    int pIndex;
    if(start < end){
        pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int main()
{
    int i, size = 6, randnum;

    int arr[6] = {10, 4, 5, 3, 9, 8};
    
    
   /** for(i=0; i<size; i++){
        randnum = rand() % 100;
        arr[i] = randnum;
    }**/
    
    printf("Before sorting: ");
    printArray(arr, size);
    
    quickSort(arr, 0, size-1);
    
    printf("\nAfter sorting: ");
    printArray(arr, size);

    return 0;
}



