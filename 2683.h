//
// Created by le.zhang on 2023/5/17.
//

#ifndef HOT100_2683_H
#define HOT100_2683_H

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int a=0;
        for (int x:derived) {
            a^=x;
        }
        for (int x:derived) {
            if(a^x!=x) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2683_H
