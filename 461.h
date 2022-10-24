//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_461_H
#define HOT100_461_H

#endif //HOT100_461_H



class Solution {
public:
    int hammingDistance(int x, int y) {
        //找出x，y中二进制位不同的部分，用x保存
        x=x^y;
        //保存汉明距离
        int sum=0;
        //y保存x中的最后一位1
        y=x&-x;
        //如果x中没有1，则推出
        while (y!=0){
            //汉明距离++
            sum++;
            //消去最后一位1
            x=x^y;
            //重新获得x最后一个1
            y=x&-x;
        }
        return sum;
    }
};