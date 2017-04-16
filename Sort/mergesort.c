# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 30
# define MAX 200

int random();
void mergeSort(int array[], int size);
void mergeArray(int a[], int aSize, int b[], int bSize);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    mergeSort(array, SIZE);
    printf("\nafter\n");
    print(array);
    return 0;
}

int random(){
    return rand() % MAX;
}

void initArray(int array[]){
    for(int i = 0; i < SIZE; ++i){
        array[i] = random();
    }
}

void print(int array[]){
    for(int i = 0; i < SIZE; ++i){
        printf("%d ", array[i]);
    }
}

void mergeSort(int array[], int size){
    if(size > 1){
        mergeSort(array, size / 2);
        mergeSort(array + size / 2, size - size / 2);
        mergeArray(array, size / 2, array + size / 2, size - size / 2);
    }
}

void mergeArray(int a[], int aSize, int b[], int bSize){
    int *temp = (int*)malloc(sizeof(int) * (aSize + bSize));
    int i, j, k;
    for(i = 0, j = 0, k =0; i < aSize && j < bSize;){
        temp[k++] = (a[i] > b[j]) ? a[i++] : b[j++];
    }  
    for(;i < aSize;){
        temp[k++] = a[i++];
    }
    for(;j < bSize;){
        temp[k++] = b[j++];
    }
    for(k = 0; k < (aSize + bSize); k++){
        a[k] = temp[k];
    }
    free(temp);
}