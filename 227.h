//
// Created by ByteDance on 2022/11/4.
//

#ifndef HOT100_227_H
#define HOT100_227_H

#include <string>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculate(string s) {
        // 操作符栈
        stack<char> operators;
        // 操作数栈
        stack<int> operands;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                do {
                    num = num * 10 + (s[i++] - '0');
                } while (i < len && s[i] >= '0' && s[i] <= '9');
                operands.push(num);
                if (i == len) break;
            }
            if (s[i] == ' ') continue;
            while (!operators.empty()&& ge(operators.top(),s[i])){
                char opt=operators.top();
                operators.pop();
                int b=operands.top();
                operands.pop();
                int a=operands.top();
                operands.pop();
                switch (opt) {
                    case '+':
                        operands.push(a + b);
                        break;
                    case '-':
                        operands.push(a - b);
                        break;
                    case '*':
                        operands.push(a * b);
                        break;
                    case '/':
                        operands.push(a / b);
                        break;
                }
            }
            operators.push(s[i]);
        }
        // 最后栈中可能有残留，比如case： 3+2*2
        while (!operators.empty()){
            char opt=operators.top();
            operators.pop();
            int b=operands.top();
            operands.pop();
            int a=operands.top();
            operands.pop();
            switch (opt) {
                case '+':
                    operands.push(a + b);
                    break;
                case '-':
                    operands.push(a - b);
                    break;
                case '*':
                    operands.push(a * b);
                    break;
                case '/':
                    operands.push(a / b);
                    break;
                default:;
            }
        }
        return operands.top();
    }

    bool ge(char a, char b) {
        return b == '+' || b == '-' || a == '*' || a == '/';
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_227_H
