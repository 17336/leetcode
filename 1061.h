//
// Created by le.zhang on 2023/5/9.
//

#ifndef HOT100_1061_H
#define HOT100_1061_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // 记录每一个字符等价的最小字典序字符
        vector<char > eqs(26);
        for (int i = 0; i < 26; ++i) {
            eqs[i] = 'a'+i;
        }
        int len=s1.size();
        for (int i = 0; i < len; ++i) {
            if(s1[i]==s2[i]) continue;
            // 更新所有与s1[i]、s2[i]等价的字符的eqs为最小
            char t= min(eqs[s1[i]-'a'],eqs[s2[i]-'a']);
            char x= max(eqs[s1[i]-'a'],eqs[s2[i]-'a']);
            for (int j = 0; j < 26; ++j) {
                if(eqs[j]==x) eqs[j]=t;
            }
        }
        string res;
        for (char c:baseStr) {
            res.push_back(eqs[c-'a']);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1061_H
