# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10
# define MAX 200

int random();
void bubbleSort(int array[]);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    bubbleSort(array);
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

void bubbleSort(int array[]){
    for(int i = 0; i < SIZE; ++i){
        for(int j = i; j < SIZE; ++j){
            if(array[i] > array[j]){
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}