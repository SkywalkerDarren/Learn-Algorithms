# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 30
# define MAX 200

int random();
void insertSort(int array[]);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    insertSort(array);
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

void insertSort(int array[]){
    int i, j;
    for(i = 1; i < SIZE; i++){
        for(j = i - 1; array[j] < array[j+1] && j >= 0; j--){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }    
}