//
// Created by 17336 on 2022/3/31.
//

#ifndef HOT100_93_H
#define HOT100_93_H

#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int len;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        len=s.size();
        if(len>12||len<4) return res;

    }

    void backtrack(string &s,int begin,int dots,string &path,){

    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_93_H
