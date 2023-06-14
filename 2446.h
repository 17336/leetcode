//
// Created by le.zhang on 2023/5/17.
//

#ifndef HOT100_2446_H
#define HOT100_2446_H

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event1[1]<event2[0]||event2[1]<event1[0]) return false;
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2446_H
