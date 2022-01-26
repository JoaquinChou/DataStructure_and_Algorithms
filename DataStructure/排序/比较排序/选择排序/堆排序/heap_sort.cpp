# include<cstdio>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapAdjust(int arr[], int i, int len) {
    // 1) 取出待调整的结点i元素
    int temp = arr[i];
    for (int k = 2*i+1; k < len; k++) {
        // 2) 找到左孩子(2*i+1)和右孩子(2*i+2)中最大记录的下标；
        if ((k + 1 < len) && (arr[k] < arr[k + 1])) {
            k++;
        }
        // 3) 若孩子结点最大记录大于i结点的元素，将两者值进行交换。完成一次非叶结点堆的调整
        if (arr[k] > temp) {
            arr[i] = arr[k];
            i = k;
        }
        else {
            break;
        }
    }
    // 4) 最后给待调整元素赋值
    arr[i] = temp;
}

void heapSort(int arr[], int len) {
    // 1、构建堆
    for (int i = len / 2; i >= 0; i--) {
        heapAdjust(arr, i, len);
    }

    // 2、调整堆
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapAdjust(arr, 0, i);
    }
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
    
}


int main() {

    int arr[] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    heapSort(arr, len);
    printArr(arr, len);
   
    return 0;
}