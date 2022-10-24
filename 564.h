//
// Created by 17336 on 2022/3/27.
//

#ifndef HOT100_564_H
#define HOT100_564_H

#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            n[0] -= 1;
            return n;
        }
        int len = n.size(), l = 0, r = len - 1;
        long long num = atoi(n.data() + 1);
        while (l < r) {
            if (n[l] != n[r]) {
                if (n[0] == '1' && num == 0) return to_string(stoi(n) - 1);
                int i = len / 2;
                while (i < len) {
                    n[i] = n[len - 1 - i];
                    ++i;
                }
                return n;
            }
            ++l;
            --r;
        }
        if (n[0] == '1' && num == 1) return to_string(stoi(n) - 2);
        if (n[0] == '9' && pow(10, len - 1) == num + 1) return to_string(stoi(n) + 2);
        if (len % 2) {
            if (n[len / 2] != '0')
                n[len / 2] -= 1;
            else n[len/2]+=1;
            return n;
        } else if (n[len / 2] == '0') {
            n[len / 2 - 1] = '1';
            n[len / 2] = '1';
        } else {
            n[len / 2 - 1] -= 1;
            n[len / 2] -= 1;
        }
        return n;
    }
};

#endif //HOT100_564_H
