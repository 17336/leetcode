//
// Created by 17336 on 2021/11/23.
//

#ifndef HOT100_859_H
#define HOT100_859_H

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        //flag记录s[i]和goal[i]第几次不相等
        int flag=0;
        //记录第一次不相等的s[i]和goal[i]
        char a1=0,b1=0;
        //x记录s中是否又出现过两次及以上的字母
        int x=0;
        for (int i = 0; i < s.size(); ++i) {
            if(x!=-1){
                //如果某个字母出现了两次以上，x=-1
                if(x&(1<<s[i]-'a'))x=-1;
                //否则记录状态
                else x|=1<<s[i]-'a';
            }
            //如果某次不相等
            if(s[i]!=goal[i]){
                flag++;
                if(flag==1){
                    a1=s[i];
                    b1=goal[i];
                }
                else if(flag==2&&(a1!=goal[i]||b1!=s[i])) return false;
                else if(flag>2) return false;
            }
        }
        if(flag==2||(flag==0&&x==-1)) return true;
        return false;
    }
};

#endif //HOT100_859_H
