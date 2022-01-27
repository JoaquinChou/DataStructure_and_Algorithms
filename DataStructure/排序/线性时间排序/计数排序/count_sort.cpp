#include <cstdio>
#include <climits>

int* count_sort(int arr[], int len) {
    // 1、找到序列的最大值和最小值
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < len; i++) {
        max = max < arr[i] ? arr[i] : max;
        min = min > arr[i] ? arr[i] : min;
    }

    // 2、定义计数数组，用0初始化计数数组
    int *cnt = new int[max - min + 1]{0};
    for (int i = 0; i < len; i++) {
        cnt[arr[i] - min]++;
    }
    // 3、计数数组变形
    for (int i = 1; i < max - min + 1; i++) {
        cnt[i] += cnt[i - 1];
    }

    // 4、根据变形后的计数数组和结果数组的下标建立关系
    int *results = new int[len];
    for (int j = 0; j < len; j++) {
        results[cnt[arr[j] - min] - 1] =arr[j]; 
        cnt[arr[j] - min]--;
    }

    return results;
}

// 若希望保持序列的稳定性

// 法一：只需要在生成结果数组的时候，将序列从后往前遍历即可
int* stable_count_sort_1(int arr[], int len) {
    // 1、找到序列的最大值和最小值
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < len; i++) {
        max = max < arr[i] ? arr[i] : max;
        min = min > arr[i] ? arr[i] : min;
    }

    // 2、定义计数数组，用0初始化计数数组
    int *cnt = new int[max - min + 1]{0};
    for (int i = 0; i < len; i++) {
        cnt[arr[i] - min]++;
    }
    // 3、计数数组变形
    for (int i = 1; i < max - min + 1; i++) {
        cnt[i] += cnt[i - 1];
    }

    // 4、根据变形后的计数数组和结果数组的下标建立关系
    int *results = new int[len];
    // for (int j = 0; j < len; j++) {
    for (int j = len - 1; j >= 0; j--) {
        results[cnt[arr[j] - min] - 1] =arr[j]; 
        cnt[arr[j] - min]--;
    }

    return results;
}

// 法二：可以从前往后遍历，只需要对变形后的计数数组加1即可。
int* stable_count_sort_2(int arr[], int len) {
    // 1、找到序列的最大值和最小值
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < len; i++) {
        max = max < arr[i] ? arr[i] : max;
        min = min > arr[i] ? arr[i] : min;
    }

    // 2、定义计数数组，用0初始化计数数组
    int *cnt = new int[max - min + 1]{0};
    for (int i = 0; i < len; i++) {
        cnt[arr[i] - min]++;
    }
    // 3、计数数组变形
    for (int i = 1; i < max - min + 1; i++) {
        cnt[i] += cnt[i - 1];
    }

    // 4、根据变形后的计数数组和结果数组的下标建立关系
    int *results = new int[len];
    for (int j = 0; j < len; j++) {
        // 此时数组的下标为1~10，下标0未被使用
        results[cnt[arr[j] - min]] = arr[j]; 
        // cnt[arr[j] - min]--;
        cnt[arr[j] - min]++;
    }

    return results;
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {101, 109, 107, 103, 108, 102, 103, 110, 107, 103};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *results;
    int *stable_results;
    printArr(arr, len);
    results = count_sort(arr, len);
    printArr(results, len);
    stable_results = stable_count_sort_1(arr, len);
    printArr(results, len);
    stable_results = stable_count_sort_2(arr, len);
    printArr(results, len);
    return 0;
}