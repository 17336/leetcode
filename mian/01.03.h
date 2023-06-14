//
// Created by le.zhang on 2023/5/16.
//

#ifndef HOT100_01_03_H
#define HOT100_01_03_H

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int j=0;
        string res;
        for (int i = 0; i < length; ++i) {
            if(S[i]==' ') res.append("%20");
            else res.push_back(S[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_01_03_H
