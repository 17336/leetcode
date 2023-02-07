//
// Created by ByteDance on 2023/1/9.
//

#include <string>
#include <map>

#ifndef HOT100_12_H
#define HOT100_12_H

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static std::vector<std::pair<int, std::string>> romans;

    std::string intToRoman(int num) {
        std::string res;
        while (num) {
            for (auto it = romans.rbegin(); it != romans.rend(); ++it) {
                if (num >= it->first) {
                    res.append(it->second);
                    num -= it->first;
                    break;
                }
            }
        }
        return res;
    }
};

std::vector<std::pair<int, std::string>> Solution::romans = {{1,    "I"},
                                                             {4,    "IV"},
                                                             {5,    "V"},
                                                             {9,    "IX"},
                                                             {10,   "X"},
                                                             {40,   "XL"},
                                                             {50,   "L"},
                                                             {90,   "XC"},
                                                             {100,  "C"},
                                                             {400,  "CD"},
                                                             {500,  "D"},
                                                             {900,  "CM"},
                                                             {1000, "M"}};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_12_H
