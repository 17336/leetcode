//
// Created by 17336 on 2021/12/10.
//

#ifndef HOT100_748_H
#define HOT100_748_H

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        vector<int> count(26, 0);
        for (const auto &item: licensePlate) {
//            if (item <= 'z' && item >= 'a') ++count[item - 'a'];
//            else if (item >= 'A' && item <= 'Z') ++count[item - 'A'];
            if (isalpha(item)) {
                ++count[tolower(item) - 'a'];
            }
        }
        int cmin=INT_MAX,index;
        for (int i = 0; i < words.size(); ++i) {
            vector<int> temp=count;
            for (const auto &item: words[i]) {
                --temp[item - 'a'];
            }
            int j=0;
            for (; j < 26; ++j) {
                if(temp[j]>0) break;
            }
            if(j==26&&cmin>words[i].size()){
                cmin=words[i].size();
                index=i;
            }
        }
        return words[index];
    }
};

#endif //HOT100_748_H
