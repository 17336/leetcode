//
// Created by le.zhang on 2023/5/16.
//

#ifndef HOT100_01_01_H
#define HOT100_01_01_H

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isUnique(string astr) {
        int bits=0;
        for (auto c:astr) {
            if(bits&1<<(c-'a')) return false;
            bits|=1<<(c-'a');
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_01_01_H
