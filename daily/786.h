//
// Created by 17336 on 2021/11/29.
//

#ifndef HOT100_786_H
#define HOT100_786_H

#include "vector"
#include "queue"

using namespace std;

struct myless {
    bool operator()(pair<double, vector<int>> const &a, pair<double, vector<int>> const &b)const {
        return a.first<b.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>,myless> heap;
        for (int i = 0; i < arr.size() - 1; ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                double temp = arr[i] * 1.0 / arr[j];
                if (heap.size() < k) {
                    heap.push({temp,{arr[i],arr[j]}});
                } else if (temp < heap.top().first) {
                    heap.pop();
                    heap.push({temp,{arr[i],arr[j]}});
                }
            }
        }
        return heap.top().second;
    }
};

#endif //HOT100_786_H
