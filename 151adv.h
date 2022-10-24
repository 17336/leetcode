//
// Created by 17336 on 2022/3/30.
//

#ifndef HOT100_151ADV_H
#define HOT100_151ADV_H

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeBlank(s);
        //整个字符串逆序，使单词之间逆序
        reverse(s.begin(), s.end());
        int i = 0, j;
        while (i < s.size()) {
            j=i;
            while (j < s.size()-1 && s[j + 1] != ' ')++j;
            //单词内部有序
            reverse(s.begin()+i,s.begin()+j+1);
            i=j+2;
        }
        return s;
    }

    //去掉多余空格
    void removeBlank(string &s) {
        //blanks记录多余空格个数，这样把后面的字母往前移动blanks，使多余空格都集中到字符串尾部。
        int blanks = 0, i = 0;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        blanks = i;
        while (i < s.size()) {
            //如果不是空格或者不是多余的空格，则向前移动；否则记录到多余空格里
            if (s[i] != ' ' || s[i - 1] != ' ')
                s[i - blanks] = s[i];
            else{
                ++blanks;
            }
            ++i;
        }
        //末尾空格只有一个也算多余空格
        if(s.back()==' ') ++blanks;
        s.erase(s.end()-blanks,s.end());
    }
};

#endif //HOT100_151ADV_H
