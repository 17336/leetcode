//
// Created by 17336 on 2021/11/29.
//

#ifndef HOT100_786ADV_H
#define HOT100_786ADV_H

#include "vector"
#include "queue"

using namespace std;

struct mygreater {
    bool operator()(vector<int> const &a, vector<int> const &b) const {
        return a[0] * b[1] > a[1] * b[0];
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        priority_queue<vector<int>, vector<vector<int>>, mygreater> heap;
        for (int j = 1; j < arr.size(); ++j) {
            heap.push({arr[0],arr[j],0,j});
        }
        int a,b;
        for (int i = 0; i < k; ++i) {
            a=heap.top()[2];
            b=heap.top()[3];
            heap.pop();
            if(a+1<b) heap.push({arr[a+1],arr[b],a+1,b});
        }
        return {arr[a],arr[b]};
    }
};

#endif //HOT100_786ADV_H
