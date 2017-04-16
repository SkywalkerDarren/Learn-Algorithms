# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10849
# define MAX 50000

int random();
void shellSort(int array[], int d);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    printf("before\n");
    print(array);
    shellSort(array, SIZE);
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

void shellSort(int array[], int size){
    int gap = size;
    for(gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            for(int j = i - gap;
                 j >= 0 && array[j] > array[j + gap];
                j -= gap)
                {
                int temp = array[j];
                array[j] = array[j+gap];
                array[j+gap] = temp;
            }
        }
    }
}
