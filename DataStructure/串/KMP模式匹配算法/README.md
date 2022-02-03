# KMP模式匹配算法
朴素模式匹配算法逐个比较，效率很低，造成低效的原因是在当前串不匹配时，主串的`i`指针需要回溯到上一次匹配起点，模式串`T`的`j`指针要进行回溯到第一个字符。<br>
KMP算法是由D.E.Knuth、J.H.Morris和V.R.Pratt三个人发表的，故叫“KMP算法”。
## 思想
算法的<b>任务</b>是对于模式串`T`，在主串`S`中进行定位，返回出现模式串`T`在主串中的位置下标。KMP算法希望<b>只改变模式串的`j`指针的回溯位置，主串`i`指针不回溯，让模式串`j`指针移动到适合的位置进行比较。</b>

[注]KMP算法仅当模式串和主串之间存在许多“部分匹配”的情况下才能体现出优势。
## 做法
1、对于模式串`T`的每个元素$t_j$，都存在一个实数$k$，使得模式串
## 复杂度

## 图解

## 参考
1、https://www.cnblogs.com/yjiyjige/p/3263858.html<br>
2、https://blog.csdn.net/dark_cy/article/details/88698736<br>
3、https://www.cnblogs.com/dusf/p/kmp.html <br>