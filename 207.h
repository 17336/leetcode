//
// Created by 17336 on 2022/3/8.
//

#ifndef HOT100_207_H
#define HOT100_207_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//拓扑排序
class Solution {
    vector<int> visited;
    unordered_map<int, vector<int>> nodes;
    unordered_set<int> path;
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        visited.resize(numCourses);
        //初始化图
        for (const auto &prerequisite: prerequisites) {
            nodes[prerequisite[1]].push_back(prerequisite[0]);
        }
        //每个节点都dfs一次
        for (int i = 0; i < numCourses; ++i) {
            if(visited[i]==0){
                path.clear();
                if(!dfs(i)) return false;
            }
        }
        return true;
    }

    bool dfs(int node) {
        //如果搜索到了搜索路径上加入过的结点
        if (path.count(node)) return false;
        if (visited[node]) return true;
        path.insert(node);
        visited[node] = 1;
        for (const auto &item: nodes[node]) {
            if(!dfs(item)) return false;
        }
        //当前节点搜索完毕退出搜索路径
        path.erase(node);
        return true;
    }
};

#endif //HOT100_207_H
