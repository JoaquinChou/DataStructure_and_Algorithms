#include<cstdio>

void straightInsertionSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int j;
        if (arr[i] < arr[i - 1]) {
            int temp = arr[i];
            for (j = i - 1; (j >= 0) && (arr[j] > temp); j--) {
                arr[j + 1] = arr[j];
                }
            arr[j + 1] = temp;
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
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    straightInsertionSort(arr, len);
    printArr(arr, len);


}