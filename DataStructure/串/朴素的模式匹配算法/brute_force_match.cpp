#include <iostream>
using namespace std;

// 从主串`S`的第pos个元素开始匹配
int bruteForceMatch(string S, string T, int pos) {
    int i = pos;
    int j = 0;
    while (i < S.size() && j < T.size()) {
        if (S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            // i又从上一次匹配的下一个位置开始
            i = i - j + 2; 
            j = 0;
        }
    }

    // string::size不跟负数比较则没有关系，否则会把前面的负值变量强转为无符号数
    if (j > T.size() - 1)   return i - T.size();
    else return -1;

}
int main() {

    string S = "sawtsafvda";
    string T = "safv";
    int res = bruteForceMatch(S, T, 0);
    if (res >= 0) {
        cout << "从主串的第" << (res + 1) << "个位置开始" << endl;
    }
    else    cout << "匹配失败" << endl;

    return 0;
}