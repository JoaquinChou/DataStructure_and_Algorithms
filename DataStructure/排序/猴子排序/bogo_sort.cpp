# include<cstdio>
# include<cstdlib>
# include<ctime>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void randomShuffle(int arr[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        // 随机生成[0, i + 1)的整数
        unsigned int swap_position = rand() % (i + 1);
        swap(arr[i], arr[swap_position]);
    }

}

bool isAscend(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1])    return true;
    }
    return false;
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
    
}

int main() {
    int arr[] = {1, 5, 8, 3, 7, 4, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    bool flag = true;
    srand((unsigned)time(NULL));
    int count = 0;

    while (flag) {
        count++;
        printf("随机第%d次\n", count);
        randomShuffle(arr, len);
        flag = isAscend(arr, len);
    }
    printArr(arr, len);
    
    return 0;
}