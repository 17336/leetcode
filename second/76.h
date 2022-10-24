//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_76_H
#define HOT100_76_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ct(52, 0), cs(52, 0);
        for (const auto &item: t) {
            ctl(ct,item,1);
        }
        int j = 0;
        int minLen = INT_MAX, l = -1;
        for (int i = 0; i < s.size(); ++i) {
            ctl(cs,s[i],1);
            if (isContain(ct, cs)) {
                while (j < i && ctl(cs,s[j],2) - 1 >= ctl(ct,s[j],2)) {
                    ctl(cs,s[j],0);
                    ++j;
                }
                if (i - j < minLen) {
                    l = j;
                    minLen = i - j + 1;
                    if (minLen == t.size()) return s.substr(l, minLen);
                }
                ctl(cs,s[j],0);
                ++j;
            }
        }
        if (l == -1) return "";
        return s.substr(l, minLen);
    }

    int ctl(vector<int> &counts,char c,int opt){
        if(opt==1){
            if(c>='a') ++counts[c-'a'];
            else ++counts[c-'A'+26];
        } else if(opt==0){
            if(c>='a') --counts[c-'a'];
            else --counts[c-'A'+26];
        } else {
            if(c>='a') return counts[c-'a'];
            return counts[c-'A'+26];
        }
        return -1;
    }

    bool isContain(vector<int> &ct, vector<int> &cs) {
        for (int i = 0; i < 52; ++i) {
            if (cs[i] < ct[i]) return false;
        }
        return true;
    }
};

#endif //HOT100_76_H
