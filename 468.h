//
// Created by ByteDance on 2022/11/16.
//

#ifndef HOT100_468_H
#define HOT100_468_H

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string validIPAddress(string queryIP) {
        int len = queryIP.size();
        if (len < 7 || len > 39) return "Neither";
        if(len<15) {
            if(ipv4(queryIP)) return "IPv4";
            return "Neither";
        }
        if(len>15){
            if(ipv6(queryIP)) return "IPv6";
            return "Neither";
        }
        for (int i = 0; i < 4; ++i) {
            if(queryIP[i]=='.') {
                if(ipv4(queryIP)) return "IPv4";
                return "Neither";
            }
        }
        if(ipv6(queryIP)) return "IPv6";
        return "Neither";
    }

    // len [3+4,3+4*3]=[7,15]
    bool ipv4(string &queryIP) {
        int len = queryIP.size(), remain = 4;
        if(queryIP[0]=='.'||queryIP[len-1]=='.') return false;
        for (int i = 0; i < len; ++i) {
            int num = 0;
            while (queryIP[i] != '.' && i < len) {
                // 前导0
                if(i>0&&queryIP[i-1]=='0'&&(i-2<0||queryIP[i-2]=='.')) return false;
                if (queryIP[i] < '0' || queryIP[i] > '9') return false;
                num = num * 10 + queryIP[i++] - '0';
                if (num > 255) return false;
            }
            // 双点case：125..124.1
            if(i<len && queryIP[i]==queryIP[i-1]) return false;
            --remain;
        }
        return !remain;
    }

    // len [7+8,7+4*8]=[15,39]
    bool ipv6(string &queryIP) {
        int len = queryIP.size(), remain = 8;
        if(queryIP[0]==':'||queryIP[len-1]==':') return false;
        for (int i = 0; i < len; ++i) {
            int l = 0;
            while (queryIP[i] != ':' && i < len) {
                if ((queryIP[i] >= '0' && queryIP[i] <= '9') || (queryIP[i] >= 'a' && queryIP[i] <= 'f') ||
                    (queryIP[i] >= 'A' && queryIP[i] <= 'F')) {
                    ++l;
                    ++i;
                    continue;
                }
                return false;
            }
            // 双::case
            if(i<len && queryIP[i]==queryIP[i-1]) return false;
            if (l > 4) return false;
            --remain;
        }
        return !remain;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_468_H
