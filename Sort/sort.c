# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 100000 //数组大小
# define MAX 100000 //最大随机数

void bubbleSort(int array[], int size);
void insertSort(int array[], int size);
void selectSort(int array[], int size);
void shellSort(int array[], int size);
void qSort(int array[], int left, int right);
int partion(int array[], int start,int end);
void mergeSort(int array[], int size);
void mergeArray(int a[], int aSize, int b[], int bSize);
void heapSort(int array[], int size);
void minHeap(int array[], int size);
void minHeapAdjust(int array[], int parent, int size);
void initArray(int array[]);
int random();

int main(){
    srand(time(NULL));
    int array[SIZE];
    clock_t start, finish;
    double second;

    initArray(array);
    printf("堆排序\n");
    start = clock();
    heapSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);

    initArray(array);
    printf("希尔排序\n"); 
    start = clock();
    shellSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);
    
    initArray(array);
    printf("快速排序\n");
    start = clock();
    qSort(array, 0, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);

    initArray(array);
    printf("归并排序\n");
    start = clock();
    mergeSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);

    initArray(array);
    printf("冒泡排序\n");
    start = clock();
    bubbleSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);
    
    initArray(array);
    printf("插入排序\n");
    start = clock();
    insertSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);

    initArray(array);
    printf("选择排序\n");
    start = clock();
    selectSort(array, SIZE);
    finish = clock();
    second = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("耗时%f秒\n", second);


    getchar();

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

//冒泡排序
void bubbleSort(int array[], int size){
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            if(array[i] > array[j]){
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}

//插入排序
void insertSort(int array[], int size){
    int i, j;
    for(i = 1; i < size; i++){
        for(j = i - 1; array[j] < array[j+1] && j >= 0; j--){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }    
}

//选择排序
void selectSort(int array[], int size){
    for(int i = 0; i < size; ++i){
        int min = i;
        int t;
        for(int j = i; j < size; ++j){
            if(array[j] < array[min]){
                min = j;
            }
        }
        t = array[min];
        array[min] = array[i];
        array[i] = t;
    }
}

//希尔排序
void shellSort(int array[], int size){
    int gap = size;
    for(gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            int j = i - gap;
            for(; j >= 0 && array[j] > array[j + gap];
                j -= gap)
                {
                int temp = array[j];
                array[j] = array[j+gap];
                array[j+gap] = temp;
            }
        }
    }
}

//快速排序
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

//归并排序
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

//堆排序
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