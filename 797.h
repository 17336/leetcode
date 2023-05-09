//
// Created by le.zhang on 2023/5/8.
//

#ifndef HOT100_797_H
#define HOT100_797_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> path;
        vector<vector<int>> res;
        path.push_back(0);
        backtrace(0,path,res,graph);
        return res;
    }

    void backtrace(int from, vector<int> &path, vector<vector<int>> &res, vector<vector<int>> &graph) {

        int n=graph.size();
        for (auto i:graph[from]) {
            path.push_back(i);
            if(i==n-1) res.push_back(path);
            else backtrace(i,path,res,graph);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_797_H
