#include <iostream>
using namespace std;

void getNext(string T, int *next) {
    int k = -1, j = 0;
    next[0] = -1;
    while (j < T.size()) {
        // 相等说明重复串的长度加1
        if (k == -1 || T[k] == T[j]) {
            j++;
            k++;
            next[j] = k;
        }
        else {
            // 检验是否有重复串时，
            // 把前面串看成是模式串，后面的串看成主串
            // 原来的i不回溯时，j = next[j]变成了下式
            k = next[k];
        }
    }
}

void optimGetNext(string T, int *next) {
    int k = -1, j = 0;
    next[0] = -1;
    while (j < T.size()) {
        // 相等说明重复串的长度加1
        if (k == -1 || T[k] == T[j]) {
            j++;
            k++;
            // 如果第j个元素，和第k(next[j])个元素的值相同的话
            // 此时如果不匹配，next[j]指向k变得毫无意义，为节省时间，应指向next[k]
            if (T[k] == T[j]) {
                next[j] = next[k];
            }
            else
                next[j] = k;
        }
        else {
            // 检验是否有重复串时，
            // 把前面串看成是模式串，后面的串看成主串
            // 原来的i不回溯时，j = next[j]变成了下式
            k = next[k];
        }
    }
}

int KMPSearch(string S, string T, int pos) {
    // string::size()返回的是一个无符号的整数。
    // 当它的返回值和一个有符号数比较时，有符号数会被隐式转换成无符号数
    // 所以用变量存下长度。
    int S_len = S.size();
    int T_len = T.size();

    int i = pos;
    int j = 0;
    // 定义next数组
    int *next = new int[T.size()];
    // 仅仅利用模式串的内容给next数组赋值
    getNext(T, next);
    for (int t = 0; t < T_len; t++) {
        cout << next[t] << "  ";
    }
    // optimGetNext(T, next);
    while (i < S_len && j < T_len) {
        if (j == -1 || S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            // i不回溯时，j = next[j]
            j = next[j];
        }
    }

    if (j > T_len - 1)  return i - T_len;
    
    else return -1;
}


int main() {

    string S = "ABACBCDHI";
    // string S = "ABABC";
    string T = "ABAB";
    
    int res = KMPSearch(S, T, 0);
    if (res >= 0) {
        cout << "从主串的第" << (res + 1) << "个位置开始" << endl;
    }
    else    cout << "匹配失败" << endl;
    return 0;
}