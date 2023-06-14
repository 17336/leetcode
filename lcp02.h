//
// Created by le.zhang on 2023/5/10.
//

#ifndef HOT100_LCP02_H
#define HOT100_LCP02_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> res{cont.back(),1};
        int i=cont.size()-2;
        while (i>=0) {
            swap(res[0],res[1]);
            res[0]+=cont[i]*res[1];
            --i;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_LCP02_H
