//
// Created by ByteDance on 2022/11/17.
//

#ifndef HOT100_9_H
#define HOT100_9_H

#include <stack>

//leetcode submit region begin(Prohibit modification and deletion)
class CQueue {
    std::stack<int> input, output;
public:
    CQueue() {

    }

    void appendTail(int value) {
        input.push(value);
    }

    int deleteHead() {
        if (output.empty())
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        if(output.empty()) return -1;
        int res = output.top();
        output.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_9_H
