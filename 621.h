//
// Created by 17336 on 2021/11/13.
//

#ifndef HOT100_621_H
#define HOT100_621_H

#endif //HOT100_621_H

#include "vector"
#include "algorithm"

using namespace std;

struct cmp {
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<pair<char, int>> heap(26, {0, 0});
        for (const auto &task: tasks) {
            if (heap[task - 'A'].first == 0) {
                heap[task - 'A'].first = task;
                heap[task - 'A'].second = 1;
            } else heap[task - 'A'].second++;
        }
        make_heap(heap.begin(), heap.end(), cmp());
        while (heap.back().second == 0) heap.pop_back();
        int time = 0;
        while (!heap.empty()) {
            int len = heap.size();
            int i = 0;
            for (; i <= n && i < len; ++i) {
                heap[i].second--;
                time++;
            }
            sort(heap.begin(),heap.end(),cmp());
            while (!heap.empty()&&heap.back().second == 0) heap.pop_back();
            if (!heap.empty()&&len-1 < n)time += n - len+1;
        }
        return time;
    }
};