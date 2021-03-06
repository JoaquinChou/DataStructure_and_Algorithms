/**
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

示例 1：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：
输入：n = 2
输出：false
**/

class Solution {
public:
    bool isHappy(int n) {
        // 1. 定义快慢指针
        int　slow_sum, fast_sum; 
        fast_sum = createNewNumber(createNewNumber(n));
        slow_sum = createNewNumber(n);
        // 2. 第一个while：找到快慢指针相遇的位置
        while (slow_sum != fast_sum)
        {
            fast_sum = createNewNumber(createNewNumber(fast_sum));
            slow_sum = createNewNumber(slow_sum);
        }
        // 3. 相遇时值必定相同，值为1是快乐数
        if (slow_sum == 1)  return true;
        return false;
    }

    // 生成新数字
    int createNewNumber(int n)
    {
        int sum = 0;
        while (n  != 0)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
        return sum;    
    }
};