//
// Created by 17336 on 2022/5/5.
//

#ifndef HOT100_2049_H
#define HOT100_2049_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<int> childs;
public:
    int countHighestScoreNodes(vector<int> &parents) {
        int n = parents.size();
        vector<pair<int, int>> tree(n, {-1, -1});
        for (int i = 1; i < n; ++i) {
            int p = parents[i];
            if (tree[p].first == -1) tree[p].first = i;
            else tree[p].second = i;
        }
        childs.resize(n, 0);
        countNums(tree, 0);
        int score = 0, num = 0;
        for (int i = 0; i < n; ++i) {
            long long curs = 1;
            if (i != 0) curs *= n - childs[i];
            if (tree[i].first > 0) curs *= childs[tree[i].first];
            if (tree[i].second > 0) curs *= childs[tree[i].second];
            if (curs == score) ++num;
            else if (curs > score) {
                score = curs;
                num = 1;
            }
        }
        return num;
    }

    int countNums(vector<pair<int, int>> &tree, int i) {
        int l = 0, r = 0;
        if (tree[i].first != -1) l = countNums(tree, tree[i].first);
        if (tree[i].second != -1) r = countNums(tree, tree[i].second);
        childs[i] = l + r + 1;
        return l + r + 1;
    }
};

#endif //HOT100_2049_H
