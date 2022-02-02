# 双指针算法
双指针算法主要有“快慢指针”和“左右指针”两种。<br>

快慢指针是指两个指针从同一侧开始遍历<b><font color='red'>链表</font></b>，每次移动步长较大的定义为快指针`fast`，移动步长较小的定义为慢指针`slow`，循环遍历链表直到两个指针值相等为止。<br>
左右指针是指在<b><font color='red'>有序数组或字符串</font></b>中，将最左侧的索引定义成左指针`left`，最右侧的索引定义为右指针`right`，然后从两头向中间进行<b><font color='red'>有序数组或字符串的遍历</font></b>。<br>
详细了解可点击[这里](https://zhuanlan.zhihu.com/p/78144008)。

  ## 1.快慢指针<br>
   一般题型为带环的链表和寻找链表中的某一位置。<br>
   带环链表伪代码如下：
   ```C++
//    1.定义快慢指针
    ListNode fast, slow;
//    2. 用头部赋值
    fast = slow = head;
    // 3. 遍历策略
    // 第一个while，找到相遇点
    while (fast != null && fast.next.next != null)
    {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow)   break;
    }
    // 第二个whie，让快慢指针同速遍历
    slow = head;
    while (slow != fast)
    {
        fast = fast.next;
        slow = slow.next;
    }
   
   ```

   寻找链表中的某一位置的伪代码如下：
   ```C++
//    1.定义快慢指针
    ListNode fast, slow;
//    2. 用头部赋值
    fast = slow = head;
    // 3. 遍历策略
    // 第一个while
    while (快指针先遍历一段路)
    {
        fast = fast.next;
    }
    // 第二个while:让慢指针和快指针同速遍历
    while (fast != null && fast.next != null) 
    {
        fast = fast.next;
        slow = slow.next;
    }
   ```

   
  ## 2.左右指针<br>
  一般题型为有序的数组或字符串。
  解题伪代码如下：
  ```c++
//   1. 先定义左右指针
    int left = 0, right = nums.size() - 1;
    // 2. 第一个while：左指针小于右指针
    while (left < right)
    {
        // 3. 进行遍历操作
        // 4. 左右指针各走一步
        left ++;
        right --;
    }
  ```