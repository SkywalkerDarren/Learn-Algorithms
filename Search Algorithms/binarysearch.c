# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define FAIL -1
# define SIZE 100000
# define MAX 200000

int random();
void qSort(int array[], int left, int right);
int partion(int array[], int start,int end);
int binarysearch(int array[], int size, int search);
void initArray(int array[]);
void print(int array[]);

int main(){
    srand(time(NULL));
    int array[SIZE];
    initArray(array);
    qSort(array, 0, SIZE - 1);
    print(array);
    int num;
    printf("search a num:");
    scanf("%d", &num);
    int local = binarysearch(array, SIZE, num);
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

int binarysearch(int array[], int size, int search){
    int left = 0;
    int right = size - 1;
    for(int mid = size / 2; left < right - 1;){
        if(search > array[mid]){
            right = mid;
        }else if(search < array[mid]){
            left = mid;
        }else{
            return mid;
        }
        mid = (left + right) / 2;
    }
    return FAIL;
}