//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_394_H
#define HOT100_394_H

#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int end;
        return decodeFrom(s, 0, &end);
    }

    string decodeFrom(string &s, int begin, int *end) {
        int len = s.size();
        string res;
        while (begin < len) {
            if (s[begin] >= '0' && s[begin] <= '9') {
                int k = myStoi(s, begin, &begin);
                string temp = std::move(decodeFrom(s, begin, &begin));
                for (int i = 0; i < k; ++i) {
                    res.append(temp);
                }
            } else if (s[begin] == ']') {
                *end = begin;
                return res;
            }
            else if (s[begin] != '[') res.push_back(s[begin]);
            ++begin;
        }
        return res;
    }

    int myStoi(string &s, int begin, int *next) {
        int res = 0;
        while (begin < s.size() && begin >= 0 && s[begin] >= '0' && s[begin] <= '9') {
            res = res * 10 + s[begin] - '0';
            ++begin;
        }
        *next = begin;
        return res;
    }
};


#endif //HOT100_394_H
