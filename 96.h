//
// Created by 17336 on 2021/10/31.
//

#ifndef HOT100_96_H
#define HOT100_96_H

#endif //HOT100_96_H

class Solution {
    //定义全局变量memo，p使得每次给一个整数n都能利用记忆化的memo
    static int memo[20];//memo[i]记录1~i组成二叉搜索树的种类数
    static int p;//p记录当前memo记录的最大二叉搜索树结点数
    static int init(){
        memo[1]=1;
        memo[2]=2;
    }
public:
    //如果当前要搜索n
    int numTrees(int n) {
        //原来搜索过n，直接返回
        if(memo[n]) return memo[n];
        //从p+1依次判断到n的搜索树数目
        for (int i = p+1; i <= n ; ++i) {
            //累加以1~n为根节点的搜索树种类数
            int temp=2*memo[i-1];
            for (int j = 2; j < i; ++j) {
                temp+=memo[j-1]*memo[i-j];
            }
            memo[i]=temp;
        }
        //更新p
        p=n;
        return memo[n];
    }
};
int Solution::p=2;//初始化
int Solution::memo[20]={0,1,2};