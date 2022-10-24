//
// Created by 17336 on 2022/3/21.
//

#ifndef HOT100_03_05_H
#define HOT100_03_05_H

#include <vector>
#include <stack>
#include <deque>

class SortedStack {
    std::stack<int> leftStack;
    std::deque<int> rightStack;
public:
    SortedStack() {

    }

    void push(int val) {
        if (isEmpty()) {
            leftStack.push(val);
            return;
        }
        int x = INT_MAX, y = INT_MIN;
        if (!rightStack.empty()) y = rightStack.back();
        if (!leftStack.empty()) x = leftStack.top();
        //如果应该插入左栈
        if (val >= x) {
            //将插入位置之上的元素移到右栈
            while (!leftStack.empty() && leftStack.top() < val) {
                rightStack.push_back(leftStack.top());
                leftStack.pop();
            }
            leftStack.push(val);
            return;
        }
        //插入到右栈中
        if (val <= y) {
            //插入位置之上元素移到左栈
            while (!rightStack.empty() && val < rightStack.back()) {
                leftStack.push(rightStack.back());
                rightStack.pop_back();
            }
            rightStack.push_back(val);
            return;
        }
        //如果左右均可，选择小的栈插入
        if (leftStack.size() < rightStack.size()) leftStack.push(val);
        else rightStack.push_back(val);
    }

    void pop() {
        if (isEmpty()) return;
        if (!rightStack.empty()) rightStack.pop_front();
        else leftStack.pop();
    }

    int peek() {
        if (isEmpty()) return -1;
        if (!rightStack.empty()) return rightStack.front();
        return leftStack.top();
    }

    bool isEmpty() {
        return leftStack.empty() && rightStack.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

#endif //HOT100_03_05_H
