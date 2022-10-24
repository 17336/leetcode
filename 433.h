//
// Created by 17336 on 2022/5/7.
//

#ifndef HOT100_433_H
#define HOT100_433_H

#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        if (start == end) return 0;
        vector<int> visited(bank.size(), 0);
        queue<string> q;
        q.push(start);
        int res = 0;
        while (!q.empty()) {
            ++res;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < bank.size(); ++j) {
                    if (visited[j] == 0 && convertable(bank[j],q.front())) {
                        if(bank[j]==end) return res;
                        q.push(bank[j]);
                        visited[j]=1;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }

    bool convertable(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++diff;
        }
        return diff == 1;
    }
};

#endif //HOT100_433_H
