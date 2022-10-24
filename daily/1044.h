//
// Created by 17336 on 2021/12/23.
//

#ifndef HOT100_1044_H
#define HOT100_1044_H

#include "string"
#include "vector"
#include "array"
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n=s.size();
        //记录重复字母的下标集合
        array<vector<int>,26> memo;
        //dp[i][j]记录以i、j为结尾字符的两子串重复的长度
        vector<vector<int>> dp(n,vector<int>(n));
        //最大重复子串的起始位置和长度
        int long_begin,long_len=0;
        for (int i = 0; i < n; ++i) {
            //temp保存以i结尾能找到最大重复子串的长度
            int temp=0;
            char c=s[i];
            //对于每一个相同结尾的子串，判断前一位结尾的字串重复长度
            for (const auto &item: memo[c-'a']) {
                if(item==0){
                    temp= max(1,dp[i][item]=1);
                }
                else{
                    temp= max(temp,dp[i][item]=1+dp[i-1][item-1]);
                }
            }
            if(temp>long_len){
                long_begin=i-temp+1;
                long_len=temp;
            }
            //当前下标加入memo
            memo[c-'a'].push_back(i);
        }
        return s.substr(long_begin,long_len);
    }
};

#endif //HOT100_1044_H
