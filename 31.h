//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_31_H
#define HOT100_31_H

#endif //HOT100_31_H

#include "vector"
using namespace std;

//思路：我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
//同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。
//这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。

//有一点我是看了题解才想起来的，对于排序不要用sort快排：
//          交换「较小数」「较大数」之后，原「较小数」之后的后缀序列是降序的，如果要排序直接双指针交换即可
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if(nums.size()==1) return;
        //从后往前找第一个升序对，即尽量靠右的升序对，p指向那个「较小数」的后一个
        auto p=nums.end()-1;
        while (p>nums.begin()){
            if(*(p-1)>=*p)p--;
            else break;
        }
        //如果整个nums都是降序的
        if(p==nums.begin()){
            //双指针交换变成升序
            sort(nums.begin(),nums.end()-1);
            return;
        }
        //找到了较小数，该找右边的「较大数」了
        else {
            //temp找右边的「较大数」
            auto temp=nums.end()-1;
            p--;
            while (temp>p&&*temp<=*p)temp--;
            //找到后交换
            swap(*temp,*p);
            //降序改升序
            sort(p+1,nums.end()-1);
            return;
        }
    }
    //降序改升序
    void sort(vector<int>::iterator begin,vector<int>::iterator end){
        while (begin<end){
            swap(*begin,*end);
            begin++;
            end--;
        }
    }
};