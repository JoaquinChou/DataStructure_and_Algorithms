# include<cstdio>

void bubbleSort(int arr[], int len) {
    for (int i = 1; i < len + 1; i++) {
        for (int j = len - 1; j >= i; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

// 优化的目标在于节省比较次数
void optimize_bubbleSort(int arr[], int len) {
    bool flag = true;
    for (int i = 1; i < len + 1 && flag; i++) {
        for (int j = len - 1; j >= i; j--) {
            flag = false;
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = true;
            }
        }
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
    bubbleSort(arr, len);
    printArr(arr, len);
    // optimize_bubbleSort(arr, len);
    // printArr(arr, len);
    return 0;
}