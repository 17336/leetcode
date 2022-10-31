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
        len = s.size();
        if (len > 12 || len < 4) return res;
        string path;
        backtrack(s, 0, 0, path);
        return res;
    }

    // s为回溯字符串，begin为回溯位置，path为回溯到当前位置的部分结果，dots是对path的补充
    void backtrack(string &s, int begin, int dots, string &path) {
        // 剩余位超了
        if (len - begin > (4 - dots) * 3) return;
        if (begin == len) {
            if (dots == 4) {
                path.pop_back();
                res.emplace_back(path);
            }
            return;
        }
        // 前导0
        if (s[begin] == '0') {
            string temp=path;
            temp.append("0.");
            backtrack(s, begin + 1, dots + 1, temp);
            return;
        }
        int i =0;
        // 回溯，尝试匹配至超过255
        while(begin<len) {
            i = i * 10 + s[begin++] - '0';
            if(i>255) return;
            string temp = path;
            temp.append(to_string(i) + '.');
            backtrack(s, begin, dots + 1, temp);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_93_H
