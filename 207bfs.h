//
// Created by 17336 on 2022/3/8.
//

#ifndef HOT100_207BFS_H
#define HOT100_207BFS_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    vector<vector<int>> nodes;
    vector<int> entry;
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        //存储所有入度为0的结点
        queue<int> q;
        //图
        nodes.resize(numCourses);
        //所有节点入度
        entry.resize(numCourses);
        for (const auto &prerequisite: prerequisites) {
            nodes[prerequisite[1]].push_back(prerequisite[0]);
            ++entry[prerequisite[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!entry[i]) q.push(i);
        }
        //访问入度为0的结点，并将其邻接点入度递减1
        while (!q.empty()) {
            int node = q.front();
            --numCourses;
            q.pop();
            for (const auto &item: nodes[node]) {
                --entry[item];
                if (entry[item] == 0) q.push(item);
            }
        }
        return numCourses==0;
    }
};

#endif //HOT100_207BFS_H
