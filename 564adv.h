//
// Created by 17336 on 2022/3/27.
//

#ifndef HOT100_564ADV_H
#define HOT100_564ADV_H

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
        int len = n.size();
        long long num = stoi(n), temp = pow(10, len - 1);
        if (num == temp) return to_string(num - 1);
        if (num == temp + 1) return to_string(num - 2);
        if (num == temp * 10 - 1) return to_string(num + 2);
        //向上取整
        string res = n.substr(0, (len + 1) / 2);
        long long half = stoi(res), x = (half - 1)==0?half:half-1, y = half, z = half + 1, rr;
        long long tx=x,ty=y,tz=z;
        if (len % 2) {
            tx /= 10;
            ty /= 10;
            tz /= 10;
        }
        while (tx > 0) {
            x = x * 10 + tx % 10;
            y = y * 10 + ty % 10;
            z = z * 10 + tz % 10;
            tx /= 10;
            ty /= 10;
            tz /= 10;
        }
        if (y == num) y = x;
        rr = min(min(num - x, y > num ? y - num : num - y), z - num);
        if (num - x == rr) return to_string(x);
        if (z - num == rr) return to_string(z);
        return to_string(y);
    }
};

#endif //HOT100_564ADV_H
