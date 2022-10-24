//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_38_H
#define HOT100_38_H

#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for (int i = 2; i <= n; ++i) {
            string next;
            int j=0;
            while (j<s.size()){
                int k=j+1;
                while (k<s.size()&&s[k]==s[j]) ++k;
                next.append(to_string(k-j));
                next.push_back(s[j]);
                j=k;
            }
            s.swap(next);
        }
        return s;
    }
};

#endif //HOT100_38_H
