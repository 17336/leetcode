//
// Created by 17336 on 2022/3/12.
//

#ifndef HOT100_399_H
#define HOT100_399_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> map;
    unordered_set<string> visited;
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            map[equations[i][0]].emplace_back(equations[i][1], values[i]);
            map[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }
        for (const auto &query: queries) {
            if (map.count(query[0]) == 0 || map.count(query[1]) == 0) res.push_back(-1.0);
            else {
                visited.clear();
                res.push_back(dfs(query[0], query[1], 1.0));
            }
        }
        return res;
    }

    double dfs(const string &a, const string &b, double sum) {
        visited.insert(a);
        if (a == b) return sum;
        for (const auto &item: map[a]) {
            if (!visited.count(item.first)) {
                double r = dfs(item.first, b, sum * item.second);
                if (r != -1.0) return r;
            }
        }
        return -1.0;
    }
};

#endif //HOT100_399_H
