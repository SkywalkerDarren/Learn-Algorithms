# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10
# define MAX 200

int random();
void qSort(int array[], int left, int right);
int partion(int array[], int start,int end);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    qSort(array, 0, SIZE - 1);
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

void qSort(int array[], int left, int right){
    if (left < right){
        int i = partion(array, left, right);
        qSort(array, left, i - 1);
        qSort(array, i + 1, right);
    }
}

int partion(int array[], int start,int end){
    int i = start, j = end;
    int temp = array[i];
    while (i < j){
        for (; i < j && array[j] < temp; j--);
        if (i < j) array[i++] = array[j];
        for (; i < j && array[i] >= temp; i++);
        if (i < j) array[j++] = array[i];
    }
    array[i] = temp;
    return i;
}