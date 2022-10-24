//
// Created by 17336 on 2022/3/22.
//

#ifndef HOT100_232_H
#define HOT100_232_H

#include <stack>

class MyQueue {
    std::stack<int> s1, s2;
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (!s2.empty()) {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }

    int peek() {
        if (!s2.empty())
            return s2.top();
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#endif //HOT100_232_H
