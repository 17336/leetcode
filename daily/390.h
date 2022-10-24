//
// Created by 17336 on 2022/1/2.
//

#ifndef HOT100_390_H
#define HOT100_390_H

#include "algorithm"

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        //初始步长为1，之后每一轮步长递增乘2
        int step=2,direction=0,left=1,right=n;
        //当左右边界不相等时，继续删除元素
        while (left!=right){
            //当前区间内剩余元素
            int len=right-left+1;
            //如果是从右往左删
            if(direction){
                //right一定变为左边下一个元素
                right-=step/2;
                //当最左边被删除的恰好为left，更新left为右边一个元素；不是恰好为left时，维持left不变
                left=((len%step)==1?(left+step/2):left);
            }
            else{
                left+=step/2;
                right=(((len%step)==1)?(right-step/2):right);
            }
            //步长每次乘2
            step<<=1;
            direction=(direction+1)%2;
        }
        return left;
    }
};

#endif //HOT100_390_H
