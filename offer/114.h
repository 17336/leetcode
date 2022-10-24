//
// Created by 17336 on 2022/5/31.
//

#ifndef HOT100_114_H
#define HOT100_114_H

#include <basi.h>

class Solution {
public:
    string alienOrder(vector<string> &words) {
        if(words.size()==1) return words[0];
        unordered_map<char,string> post;
        unordered_map<char,int> precount(26);
        vector<char> zeros;
        int len = words.size();
        for (int i = 0; i < len - 1; ++i) {
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j]) ++j;
            if (j == words[i].size() || j == words[i + 1].size()) continue;
            post[words[i][j]-'a'].push_back(words[i+1][j]);
            ++precount[words[i+1][j]-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if(precount[i]==0) zeros.push_back(i+'a');
        }
    }
};

#endif //HOT100_114_H
