//
// Created by 17336 on 2022/2/28.
//

#ifndef HOT100_76_H
#define HOT100_76_H

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 52> a{}, b{};
        int off = 26 - 'A';
        for (const auto &item: t) {
            if (islower(item))++a[item - 'a'];
            else ++a[item + off];
        }
        int left = 0, right = 0, rr = s.size(), rl = 0;
        for (; right < s.size(); ++right) {
            int temp;
            if (islower(s[right])) temp = s[right] - 'a';
            else temp = s[right] + off;
            if (b[temp] < a[temp]) {
                ++b[temp];
            } else if (s[left] != temp) {
                ++b[temp];
            } else {
                for (; left <= right; ++left) {
                    int temp = s[left];
                    if (islower(s[left])) temp -= 'a';
                    else temp += off;
                    if ((a[temp] == 0))continue;
                    if (b[temp] > a[temp]) {
                        --b[temp];
                        continue;
                    } else break;
                }
            }
            if (b == a) {
                if (right - left < rr - rl) {
                    rr = right;
                    rl = left;
                }
                for (; left <= right; ++left) {
                    int temp = s[left];
                    if (islower(s[left])) temp -= 'a';
                    else temp += off;
                    if ((a[temp] == 0))continue;
                    if (b[temp] > a[temp]) {
                        --b[temp];
                        continue;
                    } else break;
                }
            }
        }
        if (rr == s.size()) return "";
        return s.substr(left, right - left + 1);
    }
};

#endif //HOT100_76_H
