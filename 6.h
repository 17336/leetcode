//
// Created by ByteDance on 2022/10/26.
//

#ifndef HOT100_6_H
#define HOT100_6_H

#include <string>

using namespace std;

/**
 * 如下示例：按行逐行遍历，假设遍历到第i行，则依次插入i,i+2(h-i-1),i+2(h-i-1)+2i......
 * 0      6       12
 * 1    5 7    11
 * 2  4   8  10
 * 3      9
 */

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows>=n||numRows==1) return s;
        string res;
        for (int i = 0; i < numRows; ++i) {
            int j=i;
            bool flag=true;
            if(i==numRows-1) flag= false;
            while (j<n){
                res.push_back(s[j]);
                j+=flag?(2*(numRows-i-1)):2*i;
                if(i==0||i==numRows-1) continue;
                flag=!flag;
            }
        }
        return res;
    }
};

#endif //HOT100_6_H
