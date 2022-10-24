//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_17DP_H
#define HOT100_17DP_H

#endif //HOT100_17DP_H

#include "vector"
#include "string"

using namespace std;

class Solution {
    const string keyboard[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for (const auto &digit: digits) {
            if (res.empty()) {
                for (const auto &item: keyboard[digit - '0']) {
                    res.push_back(string{item});
                }
            } else {
                //如果对容器res进行了增删，再用foreach、迭代器、.size()等结构会出错，
                // 这种情况尽量用fori
                //错误示例：
//                for (string &item: res) {
//                    string temp = item;
//                    for (int i = 0; i < keyboard[digit - '0'].size() - 1; i++) {
//                        temp.push_back(keyboard[digit - '0'][i]);
//                        res.push_back(temp);
//                        temp.pop_back();
//                    }
//                    item.push_back(keyboard[digit - '0'].back());
//                }
                //使用fori，不受增删的影响
                int len = res.size();
                for (int j = 0; j < len; j++) {
                    string temp = res[j];
                    for (int i = 0; i < keyboard[digit - '0'].size() - 1; i++) {
                        temp.push_back(keyboard[digit - '0'][i]);
                        res.push_back(temp);
                        temp.pop_back();
                    }
                    res[j].push_back(keyboard[digit - '0'].back());
                }
            }
        }
        return res;
    }
};