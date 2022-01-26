#include <cstdio>

void shell_sort(int *arr, int len) {
    // 1、初始化增量为gap，每次循环增量gap减小为原来的一半；
    for (int gap = len / 2; gap > 0; gap /= 2) {
        // 2、从第gap个元素开始，分组中待插入的元素和距离为前一个gap的元素进行比较，看是否需要插入
        for (int i = gap; i < len; i++) {
            if (arr[gap] < arr[i - gap]) {
                // 3、带插入的元素称为哨兵，将哨兵从后往前，按照gap的距离，依次和顺序表的元素进行比较
                int temp = arr[i];
                int j;
                // 4、比哨兵大则往后挪一位，循环结束时在相应位置插入哨兵
                for (j = i - gap; j >=0 && arr[j] > temp; j-= gap) {
                    arr[j + gap] = arr[j];
                }
                arr[j + gap] = temp;
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

    int arr[10] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    shell_sort(arr, len);
    printArr(arr, len);
    return 0;
}