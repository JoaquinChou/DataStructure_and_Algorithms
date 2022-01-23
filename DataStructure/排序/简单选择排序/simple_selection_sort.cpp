# include<cstdio>
# include<cstdlib>
# include<ctime>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
    
}

void simple_selection_sort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min])    min = j;
        }
        if (i != min)
            swap(arr[i], arr[min]);
    }
    
}

int main() {
    int arr[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);

    simple_selection_sort(arr, len);
    printArr(arr, len);
    
    return 0;
}