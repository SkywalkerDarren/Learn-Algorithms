# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 100
# define MAX 200

int random();
void heapSort(int array[], int size);
void minHeap(int array[], int size);
void minHeapAdjust(int array[], int parent, int size);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    heapSort(array, SIZE);
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

void heapSort(int array[], int size){
    for(int i = size; i > 0;){
        minHeap(array, i);
        i--;
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
    }
}

void minHeap(int array[], int size){
    for(; size > 0;size /= 2){
        minHeapAdjust(array, 0, size);
    }
}

void minHeapAdjust(int array[], int parent, int size){
    int node;
    for(;parent < size / 2 ;parent++){
        int child = parent * 2 + 1;
        if(array[child + 1] < array[child] && child + 1 < size){
            child++;
        }
        if(array[child] < array[parent]){
            node = array[parent];
            array[parent] = array[child];
            array[child] = node;
        }
    }
    
}