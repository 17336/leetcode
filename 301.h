//
// Created by 17336 on 2021/11/25.
//

#ifndef HOT100_301_H
#define HOT100_301_H

#include "string"
#include "vector"

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> removeInvalidParentheses(string s) {
        int rInvalid = 0, lInvalid = 0;
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++l;
            if (s[i] == ')') {
                if (l <= 0) ++rInvalid;
                else --l;
            }
        }
        int r = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') ++r;
            if (s[i] == '(') {
                if (r <= 0) ++lInvalid;
                else --r;
            }
        }
    }

    void removeRightInvalid(string &s, string &path, int lInvalid, int rInvalid, int i) {
        if (rInvalid == 0) removeLeftInvalid(s, lInvalid, s.size() - 1);
        int l = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[i] == '(') {
                ++l;
                path.push_back('(');
            } else if (s[i] == ')') {
                if (l >= 0) {
                    if (rInvalid == 0) {
                        string path2;
                        removeLeftInvalid(path, path2, lInvalid, path.size() - 1);
                        return;
                    } else {
                        --rInvalid;
                        removeRightInvalid(s,path,lInvalid,rInvalid,i+1);
                        ++rInvalid;
                    }
                }
            } else path.push_back(s[i]);
        }
    }

    void removeLeftInvalid(string &s, string &path, int lInvalid, int i) {
        if (lInvalid == 0) res.push_back(s);

    }
};

#endif //HOT100_301_H


