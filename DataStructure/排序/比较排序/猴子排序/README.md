# Bogo排序
## 思想
<b>不断打乱元素，直到有序为止。</b><br>
将数组的元素当成卡片，将一堆卡片抛起，落在桌面时查看是否排序整齐，否则再抛一次。猴子排序思想出自“无限猴子定理”——让猴子在打字机上随机按键，当打字的时间足够长，能打出给定的文字，如“莎士比亚的全套著作”。

## 做法
1、查看元素是否有序。<br>
2、元素无序，那么就打乱顺序。<br>
3、再次检查元素是否有序。<br>
4、如果有序，排序成功，否则继续重复上述步骤。<br>

## 复杂度
最好时间：`O(n)` <br>
最坏时间：`O(∞)` <br>
平均时间：`O(n*n!)` <br>
稳定性：不稳定
