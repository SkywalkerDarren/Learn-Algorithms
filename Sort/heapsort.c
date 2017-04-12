# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 70
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
    minHeap(array, size);
    for(int i = size; i > 0;){
        minHeapAdjust(array, 0, i);
        i--;
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
    }
}

void minHeap(int array[], int size){ //自下至上建小根堆
    for(int parent = size / 2 - 1; parent >= 0; parent--){
        minHeapAdjust(array, parent, size);
    }
}

void minHeapAdjust(int array[], int parent, int size){ //自顶向下调整   
    int child = parent * 2 + 1;
    while(child < size){
        if(array[child + 1] < array[child] && child + 1 < size){
            child++;
        }
        if(array[child] < array[parent]){
            int node = array[parent];
            array[parent] = array[child];
            array[child] = node;
        }else{
            break;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}