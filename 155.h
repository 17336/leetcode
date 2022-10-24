//
// Created by 17336 on 2021/12/4.
//

#ifndef HOT100_155_H
#define HOT100_155_H

#include "vector"
#include "stack"

using namespace std;

class MinStack {
    vector<int> s;
    stack<int> decrease;
public:
    MinStack() {

    }

    void push(int val) {
        s.push_back(val);
        if (decrease.empty()||val <= decrease.top()) decrease.push(val);
    }

    void pop() {
        if(decrease.top()==s.back()) decrease.pop();
        s.pop_back();
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return decrease.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif //HOT100_155_H
