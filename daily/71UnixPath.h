//
// Created by 17336 on 2022/1/6.
//

#ifndef HOT100_71UNIXPATH_H
#define HOT100_71UNIXPATH_H

#include "string"
#include "vector"

using namespace std;
/./AC/.././A
class Solution {
public:
    string simplifyPath(string path) {
        // 末尾加上哨兵/，避免边界检查
        path.push_back('/');
        // 当前路径组成部分放入栈中
        vector<string> stack;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') continue;
            //遇到.目录，跳过
            if (path[i] == '.' && path[i + 1] == '/') {
                i += 1;
                continue;
            }
            //遇到..目录，从栈中弹出一个文件
            if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] == '/') {
                i += 2;
                if (!stack.empty()) stack.pop_back();
                continue;
            }
            // 如果当前文件名不是 /  .  ..  则可以放心的入栈
            stack.emplace_back();
            while (path[i] != '/') {
                stack.back().push_back(path[i++]);
            }
        }
        string res;
        for (const auto &item: stack) {
            res.push_back('/');
            res += item;
        }
        if(res.empty()) res.push_back('/');
        return res;
    }
};

#endif //HOT100_71UNIXPATH_H
