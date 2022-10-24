//
// Created by 17336 on 2021/11/28.
//

#ifndef HOT100_438_H
#define HOT100_438_H

#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> count(26, 0);
        //记录p中字母出现次数
        for (const auto &item: p) {
            count[item - 'a']++;
        }
        //双指针head、tail指向s区间子串可能为p的异位词
        int head = 0, tail = 0, lenp = p.size(), lens = s.size();
        //temp在循环中记录p剩余还需要匹配的字母个数
        vector<int> temp = count;
        while (tail < s.size()) {
            //如果head后子串长度不够用
            if (lens - head  < lenp) return res;
            //tail尽可能延申直到找到异位词，或者不匹配
            while (tail - head + 1 <= lenp && temp[s[tail] - 'a']) {
                temp[s[tail] - 'a']--;
                tail++;
            }
            //找到异位词，整个区间向前移动一格
            if (tail - head + 1 > lenp) {
                res.push_back(head);
                temp[s[head++] - 'a']++;
            }
            //如果重复字母超出，整个区间向前移一格
            else if (count[s[tail]-'a']) {
                temp[s[head++] - 'a']++;
            }
            //tail为p中没有的字母，head直接移动到tail下一格
            else {
                temp = count;
                head = ++tail;
            }
        }
        return res;
    }
};

#endif //HOT100_438_H
