//
// Created by 17336 on 2021/10/31.
//

#ifndef HOT100_500_H
#define HOT100_500_H

#endif //HOT100_500_H

#include "vector"
#include "string"
#include "unordered_set"
using namespace std;

class Solution {
    unordered_set<char> first;
    unordered_set<char> second;
public:
    Solution(){
        string f="qwertyuiop",s="asdfghjkl";
        for (int i = 0; i < 10; ++i) {
            first.insert(f[i]);
            first.insert(f[i]-32);
        }
        for (int i = 0; i < 9; ++i) {
            second.insert(s[i]);
            second.insert(s[i]-32);
        }
    }
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        for (const auto &word: words) {
            if(first.count(word[0])){
                int i = 0
                for (; i < word.size(); ++i) {
                    if(first.count(word[i])==0) break;
                }
                if(i==word.size()) res.push_back(word);
            }
            else if(second.count(word[0])){
                int i = 0
                for (; i < word.size(); ++i) {
                    if(second.count(word[i])==0) break;
                }
                if(i==word.size()) res.push_back(word);
            }
            else {
                int i = 0
                for (; i < word.size(); ++i) {
                    if(second.count(word[i])||first.count(word[i])) break;
                }
                if(i==word.size()) res.push_back(word);
            }
        }
        return res;
    }
};