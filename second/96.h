//
// Created by 17336 on 2022/5/13.
//

#ifndef HOT100_96_H
#define HOT100_96_H

#include <vector>

using namespace std;

class Solution {
    vector<int> memo;
public:
    Solution() : memo(20, 0) {

    }

    int numTrees(int n) {
        if (memo[n]) return memo[n];
        if (n == 0) return 1;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += numTrees(n - i) * numTrees(i - 1);
        }
        memo[n]=res;
        return res;
    }
};

#endif //HOT100_96_H
