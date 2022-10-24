//
// Created by 17336 on 2022/3/18.
//

#ifndef HOT100_KMP_H
#define HOT100_KMP_H

#include <vector>
#include <string>

using namespace std;

class kmp {
    vector<int> next;
public:
    void cNext(string &pat) {
        if (pat.empty()) return;
        next.resize(pat.size(), 0);
        //初始化j、k、next[0]
        int k = -1, j = 0;
        next[0] = k;
        //已知next[j]，求next[j+1]
        while (j < pat.size()-1) {
            if (k==-1 || pat[k] == pat[j]) next[++j] = ++k;
            else k = next[k];
        }
    }

    int search(string &txt, string &pat) {
        if(pat.empty()) return 0;
        cNext(pat);
        int i = 0, j = 0;
        while (i < txt.size() && j < pat.size()) {
            //如果字符匹配,i,j后移
            if (txt[i] == pat[j]) {
                ++j;
                ++i;
            }
            //不匹配，j跳转到next[j]；如果跳到了-1,i,j再跳一步
            else {
                j = next[j];
                if(j==-1){
                    ++j;
                    ++i;
                }
            }
        }
        //当j=pat.size，说明j前面的字符都匹配上了，i位置减去j长度即为第一个匹配字符的位置
        if(j==pat.size()) return i-j;
        //否则，未匹配成功
        return -1;
    }
};

#endif //HOT100_KMP_H
