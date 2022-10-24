//
// Created by 17336 on 2022/5/6.
//

#ifndef HOT100_933_H
#define HOT100_933_H

#include <queue>

using namespace std;

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);
        int beg = t - 3000;
        while (q.front() < beg) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

#endif //HOT100_933_H
