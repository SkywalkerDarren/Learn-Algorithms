# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10
# define MAX 10
# define FAIL -1

int random();
int sequenceSearch(int array[], int size, int search);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    int num;
    initArray(array);
    print(array);
    printf("\nsearch a number:");
    scanf("%d", &num);
    int local = sequenceSearch(array, SIZE, num);
    if(FAIL != local){
        printf("find\n");
    }else{
        printf("not find\n");
    }

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

int sequenceSearch(int array[], int size, int search){
    for(int i = 0; i < size; i++){
        if(search == array[i]){
            return i;
        }
    }
    return FAIL;
}