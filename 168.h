//
// Created by 17336 on 2022/4/27.
//

#ifndef HOT100_168_H
#define HOT100_168_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber){
            res.push_back('A'+(columnNumber-1)%26);
            columnNumber=(columnNumber-1)/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

#endif //HOT100_168_H
