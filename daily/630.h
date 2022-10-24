//
// Created by 17336 on 2021/12/14.
//

#ifndef HOT100_630_H
#define HOT100_630_H

#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

struct myless {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return a[1] < b[1];
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(),courses.end(),myless());
        priority_queue<int> heap;
        int startable=1,res=0;
        for (const auto &course: courses) {
            if(startable+course[0]-1<=course[1]) {
                heap.push(course[0]);
                startable+=course[0];
                res++;
            }
            else if(!heap.empty()&&course[0]<heap.top()){
                startable+=course[0]-heap.top();
                heap.pop();
                heap.push(course[0]);
            }
        }
        return res;
    }
};

#endif //HOT100_630_H
