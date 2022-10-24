//
// Created by 17336 on 2022/1/21.
//

#ifndef HOT100_1345_H
#define HOT100_1345_H

#include "vector"
#include "unordered_map"
#include "queue"
#include "unordered_set"

using namespace std;

class Solution {
    //map记录arr中某个值出现过的所有下标
    unordered_map<int, unordered_set<int>> map;
public:
    int minJumps(vector<int> &arr) {
        int n = arr.size();
        //BFS队列q
        queue<int> q;
        //初始化map
        for (int i = 1; i < arr.size(); ++i) {
            map[arr[i]].insert(i);
        }
        q.push(0);
        int steps = -1;
        while (!q.empty()) {
            int nums=q.size();
            ++steps;
            for (int i = 0; i < nums; ++i) {
                int p = q.front();
                if (p == n - 1) return steps;
                q.pop();
                //如果左节点没访问过
                if (p>=1&&map[arr[p - 1]].count(p - 1)) {
                    q.push(p - 1);
                    map[arr[p - 1]].erase(p - 1);
                }
                //如果右节点没访问过
                if (p<n-1&&map[arr[p + 1]].count(p + 1)) {
                    q.push(p + 1);
                    map[arr[p + 1]].erase(p + 1);
                }
                //对于所有等值未访问过的结点
                for (const auto &item: map[arr[p]]) {
                    q.push(item);
                }
                map.erase(arr[p]);
            }
        }
        return -1;
    }
};

#endif //HOT100_1345_H
