# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10
# define MAX 200

int rand();
void selectSort(int array[]);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    selectSort(array);
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

void selectSort(int array[]){
    for(int i = 0; i < SIZE; ++i){
        int min = i;
        int t;
        for(int j = i; j < SIZE; ++j){
            if(array[j] < array[min]){
                min = j;
            }
        }
        t = array[min];
        array[min] = array[i];
        array[i] = t;
    }
}