//
// Created by 17336 on 2021/11/27.
//

#ifndef HOT100_519MAP_H
#define HOT100_519MAP_H

#include "vector"
#include "cstdlib"
#include "unordered_map"
using namespace std;

class Solution {
    int p,q;
    int len;
    unordered_map<int,int> map;
public:
    Solution(int m, int n):p(m),q(n),len(m*n) {

    }

    vector<int> flip() {
        //随机选一个下标ran，同时len--更新备选集合边界
        int ran=rand()%(len--);
        //ran对应的二维下标row，arr
        int row,arr;
        //如果ran已经选过了，选择交换元素map[ran]
        if(map.count(ran)){
            row=map[ran]/q;
            arr=map[ran]%q;
        }
        else {
            row=ran/q;
            arr=ran%q;
        }
        //通过交换尾部元素达到“删去ran”的目的
        if(map.count(len)) map[ran]=map[len];
        else map[ran]=len;
        return {row,arr};
    }

    void reset() {
        len=p*q;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

#endif //HOT100_519MAP_H
