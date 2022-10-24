//
// Created by 17336 on 2021/11/10.
//

#ifndef HOT100_11MYSELFSOLUTION_H
#define HOT100_11MYSELFSOLUTION_H

#endif //HOT100_11MYSELFSOLUTION_H


#include "vector"
#include "queue"
#include "stack"
using namespace std;
//error solution
class Solution {
public:
    int maxArea(vector<int> &height) {
        vector<int> right(height.size(),-1),left(height.size(),-1);
        stack<int> mono;
        //找右边第一个大于a[i]的
        for (int i = 0; i < height.size(); ++i) {
            while (!mono.empty()&&height[i]>=height[mono.top()]){
                right[mono.top()]=i;
                mono.pop();
            }
            mono.push(i);
        }
        //找右边最后一个大于a[i]的,但是有错误
        for (int i = height.size()-1; i >=0 ; --i) {
            int temp=i;
            while (right[temp]!=-1)temp=right[temp];
            right[i]=(temp==i?-1:temp);
        }
        //左边同理
        mono=stack<int> ();
        for (int i = height.size()-1; i >=0; --i) {
            while (!mono.empty()&&height[i]>=height[mono.top()]){
                left[mono.top()]=i;
                mono.pop();
            }
            mono.push(i);
        }
        for (int i = 0; i <height.size() ; ++i) {
            int temp=i;
            while (left[temp]!=-1)temp=left[temp];
            left[i]=(temp==i?-1:temp);
        }

        int maxArea=0;
        for (int i = 0; i < height.size(); ++i) {
            maxArea= max(right[i]==-1?0:(right[i]-i)*height[i],left[i]==-1?0:(i-left[i])*height[i]);
        }
        return maxArea;
    }
};