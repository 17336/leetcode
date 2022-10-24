//
// Created by 17336 on 2022/5/6.
//

#ifndef HOT100_347_H
#define HOT100_347_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counts;
        for (const auto &item: nums) {
            ++counts[item];
        }
        vector<int> heap;
        for (const auto &item: counts) {
            if (heap.size() >= k && item.second <= counts[heap.front()])continue;
            if (heap.size() >= k) {
                pop_heap(heap.begin(), heap.end(),
                         [&counts](const int a, const int b) { return counts[a] > counts[b]; });
                heap.pop_back();
            }
            heap.push_back(item.first);
            push_heap(heap.begin(), heap.end(),
                      [&counts](const int a, const int b) { return counts[a] > counts[b]; });
        }
        return heap;
    }
};

#endif //HOT100_347_H
