//
// Created by 17336 on 2022/3/31.
//

#ifndef HOT100_93_H
#define HOT100_93_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        backTrack(s, 0, 0, path);
        return res;
    }

    void backTrack(string &s, int begin, int count, string &path) {
        if (count == 4 && begin != s.size()) return;
        if(count==4) res.push_back(path);
        int i = begin, cur = 0;
        while (i < begin + 3 && i < s.size()) {
            cur = cur * 10 + s[i] - '0';
            if (cur <= 255) {
                path.push_back(s[i++]);
                if (i == s.size()) {
                    if (count == 3)
                        res.push_back(path);
                    return;
                }
                path.push_back('.');
                backTrack(s, i, count + 1, path);
                path.pop_back();
                path.pop_back();
            } else break;
        }
    }
};

#endif //HOT100_93_H
