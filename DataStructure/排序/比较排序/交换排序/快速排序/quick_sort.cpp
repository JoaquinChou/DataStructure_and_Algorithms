#include <cstdio>

// 1、定义`Partition`函数，返回值是`pivotkey`最后存放序列的下标`pivot`
int Partition(int *arr, int low, int high) {
    // 2、3个定义
    int pivotkey = arr[low];
    // 3、3个循环，一个大循环，先是high循环，再是low循环
    while (low < high) {
        while (low < high && pivotkey < arr[high])   high--;
        arr[low] = arr[high];
        while (low < high && pivotkey > arr[low])    low++;
        arr[high] = arr[low];
    }
    // 4、最后`low`和`high`相遇后，返回`low`或者`high`作为当前序列的`pivot`；
    arr[low] = pivotkey;

    return low;
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int *arr, int low, int high) {
    // 5、递归`(0, pivot-1)`和`(pivot+1, arr.length())`两个子序列。
    if (low < high) {
        int pivot = Partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    int arr[] = {50, 10, 90, 30, 70, 40, 80, 60, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    quickSort(arr, 0, len - 1);
    printArr(arr, len);
    return 0;
}
