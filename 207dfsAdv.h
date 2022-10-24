//
// Created by 17336 on 2022/3/8.
//

#ifndef HOT100_207DFSADV_H
#define HOT100_207DFSADV_H

#include <vector>

using namespace std;

class Solution {
    vector<int> visited;
    vector<vector<int>> nodes;
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        nodes.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &prerequisite: prerequisites) {
            nodes[prerequisite[1]].push_back(prerequisite[0]);
        }
        for (int i=0;i<numCourses;++i) {
            if (visited[i] == 0) {
                if (!dfs(i)) return false;
            }
        }
        return true;
    }

    bool dfs(int node) {
        //一进来先置为搜索中
        visited[node]=1;
        for (const auto &item: nodes[node]) {
            //如果邻接点为搜索中，有环
            if (visited[item] == 1) return false;
            //如果未搜索，搜索之
            if (visited[item] == 0) {
                visited[item] = 1;
                if (!dfs(item))return false;
            }
        }
        //搜索完毕
        visited[node] = 2;
        return true;
    }
};

#endif //HOT100_207DFSADV_H
