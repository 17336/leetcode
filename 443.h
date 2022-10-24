//
// Created by 17336 on 2022/4/27.
//

#ifndef HOT100_443_H
#define HOT100_443_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int i = 0;
        for (int j = 0; j < chars.size(); ++j) {
            int count = 1;
            while (j + 1 < chars.size() && chars[j + 1] == chars[j]) {
                ++count;
                ++j;
            }
            if (count == 1) chars[i++] = chars[j];
            else {
                chars[i++] = chars[j];
                string s = to_string(count);
                for (const auto &item: s) {
                    chars[i++] = item;
                }
            }
        }
        return i;
    }
};

#endif //HOT100_443_H
