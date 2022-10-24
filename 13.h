//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_13_H
#define HOT100_13_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int> map{{'I', 1},
                                 {'V', 5},
                                 {'X', 10},
                                 {'L', 50},
                                 {'C', 100},
                                 {'D', 500},
                                 {'M',1000}};
public:
    int romanToInt(string s) {
        int i = 0, res = 0;
        while (i < s.size()) {
            if (i + 1 < s.size()&&map[s[i+1]]>map[s[i]]) {
                res+=map[s[i+1]]-map[s[i]];
                i+=2;
            } else res+=map[s[i++]];
        }
        return res;
    }
};

#endif //HOT100_13_H
