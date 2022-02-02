# 滑动窗口算法
## 思想
滑动窗口算法是指维护一个窗口，将窗口不停的滑动，然后更新答案。<br>
可将滑动窗口理解成打孔机，数据理解成打孔纸带，每次通过动态或静态的滑动窗口处理局部数据，进而达到处理全局数据的效果。

## 滑动窗口算法框架(做法)
滑动窗口算法一般应用于解决<b><font color='red'>子串问题</font></b>。（滑动窗口老猛男，子串问题全靠它。左右指针滑窗口，一前一后起头进。）<br><br>
滑动窗口算法伪代码框架如下：
```C++
// 判断s中是否存在t
void SlidingWindow (string s, string t)
{
    unordered_map<char , int> need, window;
    // 第一个for：代求的子串
    for (char c : t)  need[c] ++;
    // 初始化窗口的左右两端和满足条件的字符个数
    int left, right, valid;
    left = right = valid = 0;
    // 第一个while：窗口开始滑动
    while (right < s.size())
    {
        // 定义需要移入窗口的字符
        char in = s[right];
        // 右移窗口
        right ++;
        // 两个if：判断窗口数据和valid变量是否要更新
        if (need.count(in))
        {
            window[in] ++;
            if (window[in] == need[in])
                valid ++;
        }

        /***************debug位置***************/
        cout << "left=" << left <<" " << "right=" << right << endl;

        // 判断左窗口是否需要收缩
        // 一般收缩条件为right - left >= t.size()
        while (window need shrink)
        {
            char out = s[left];
            // 左移窗口
            left ++;
            // 进行窗口内数据更新
            if (need.count(out))
            {
                if (window[out] == need[out])
                    valid --;
                window[d] --;
            }
        }


    }
}
```

## 参考资料：
1.[滑动窗口算法（Sliding Window Algorithm）](https://blog.csdn.net/lm278858445/article/details/88189212)<br>

2.[滑动窗口技巧](https://labuladong.gitbook.io/algo/mu-lu-ye-1/mu-lu-ye-3/hua-dong-chuang-kou-ji-qiao-jin-jie)