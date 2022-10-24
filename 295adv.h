//
// Created by 17336 on 2022/4/22.
//

#ifndef HOT100_295ADV_H
#define HOT100_295ADV_H

#include <queue>

using namespace std;

class MedianFinder {
    //左堆为大根堆，右堆为小根堆
    priority_queue<int,vector<int>,less<int>> pre;
    priority_queue<int,vector<int>,greater<int>> post;
    int len=0;
public:
    MedianFinder():pre(less<int>()),post(greater<int>()) {

    }

    void addNum(int num) {
        if(pre.empty()) pre.push(num);
        //当插入前长度为奇数，插入后要保证右堆插入一个元素
        else if(len%2){
            if(num>pre.top()) post.push(num);
            else{
                post.push(pre.top());
                pre.pop();
                pre.push(num);
            }
        }
        //插入前长度为偶数，插入后保证左堆插入一个元素
        else{
            if(num<= post.top()) pre.push(num);
            else{
                pre.push(post.top());
                post.pop();
                post.push(num);
            }
        }
        ++len;
    }

    double findMedian() {
        if(len%2) return pre.top();
        return (pre.top()+post.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //HOT100_295ADV_H
