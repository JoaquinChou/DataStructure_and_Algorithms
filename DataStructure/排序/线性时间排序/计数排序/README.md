# 计数排序
## 思想
是一种线性时间的排序算法。它是利用计数数组`cnt[]`统计原序列元素出现的次数，<b>利用次数的累加关系</b>生成有序的结果数组对应下标。

## 使用限制
1、排序的元素必须是整数；<br>
2、排序的元素要均匀落在一定的范围内。<br>

## 做法
1、遍历序列，找出序列的`max`和`min`；<br>
2、初始化计数数组`cnt[]`长度为`max-min+1`，统计`元素-min`的出现次数；<br>
3、计数数组变形(即累加操作)：`cnt[i] += cnt[i - 1]`；<br>
4、填充空的结果数组，生成结果数组的下标：`result[cnt[arr[j] - min] - 1] = A[j]`。<br>

## 复杂度
时间：`O(n)`<br>
空间：`O(n)`<br>
稳定性：可通过代码设定稳定或不稳定<br>

## 图解
待排序序列`arr[] = {101, 109, 107, 103, 108, 102, 103, 110, 107, 103}`<br>
<img src="../figures/count_sort_0.png"/>
<img src="../figures/count_sort_1.png"/>
<img src="../figures/count_sort_2.png"/>
<img src="../figures/count_sort_3.png"/>
<img src="../figures/count_sort_4.png"/>
<img src="../figures/count_sort_5.jpg"/>

## 参考
https://www.cnblogs.com/xiaochuan94/p/11198610.html