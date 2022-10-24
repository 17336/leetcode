//
// Created by 17336 on 2021/11/2.
//

#ifndef HOT100_139_H
#define HOT100_139_H

#endif //HOT100_139_H

#include "string"
#include "vector"
#include "unordered_set"
using namespace std;

//字典树
struct Tire {
    Tire *next[26] = {nullptr};
    bool now_end = false;
public:
    //插入字符串word
    void insert(const string &word) {
        Tire *p = this;
        for (const auto &item: word) {
            if (p->next[item - 'a'] == nullptr) p->next[item - 'a'] = new Tire();
            p = p->next[item - 'a'];
        }
        p->now_end = true;
    }
};

class Solution {
    //备忘录，用于存放已经判断过的不可拆分的字符串（可拆分的不用存，因为一旦可拆分一定return true了）
    unordered_set<int> memo;
    Tire *root = new Tire();
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        for (const auto &item: wordDict) {
            root->insert(item);
        }
        return backtrack(s,0);
    }

    bool backtrack(const string &s,int x) {
        Tire *p = root;
        for (int i = x; i < s.size(); i++) {
            //如果某个字符在字典树中不存在，则以x起始的子串不可拆分，记录x
            if (p->next[s[i] - 'a'] == nullptr){
                memo.insert(x);
                return false;
            }
            p = p->next[s[i] - 'a'];
            if (p->now_end && (i==s.size()-1||(!memo.count(i+1)&&backtrack(s,i+1))))return true;
        }
        //如果最后一个字符判断完p->now_end为false
        memo.insert(x);
        return false;
    }
};