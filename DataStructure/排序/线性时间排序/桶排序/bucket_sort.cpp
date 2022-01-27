#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// 有序桶+快排
void order_bucket_sort(int arr[], int bucket_num, int len) {
    // 1、找到序列的最大值和最小值
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < len; i++) {
        max = max < arr[i] ? arr[i] : max;
        min = min > arr[i] ? arr[i] : min;
    }

    // 2、根据桶的数量创建桶数组
    bucket_num = (len < bucket_num ? len : bucket_num);
    vector<vector<int>> buckets(bucket_num);
    // 每个桶中的至多的元素数量为
    int num_per_bucket = ceil((max - min) * 1.0 / bucket_num);
    int bucket_index;
    // 3、把数据放入桶中
    for (int i = 0; i < len; i++) {
        bucket_index = (arr[i] - min) / num_per_bucket;
        printf("数据%d在第%d个桶中\n", arr[i], bucket_index);
        buckets[bucket_index].emplace_back(arr[i]);
    }
    // 4、桶内的元素使用系统自带的排序(也就是快速排序)，并且赋值原数组
    int insert_index = 0;
    for (auto bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        // 输出新序列
        for (int i = 0; i < bucket.size(); i++) {
            arr[insert_index] = bucket[i];
            insert_index++;
        }
    }
}


void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {18, 11, 28, 45, 23, 50};
    const int BUCKET_NUM = 4;
    int len = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, len);
    order_bucket_sort(arr, BUCKET_NUM, len);
    printArr(arr, len);
   
    return 0;
}