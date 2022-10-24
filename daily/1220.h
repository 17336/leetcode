//
// Created by 17336 on 2022/1/18.
//

#ifndef HOT100_1220_H
#define HOT100_1220_H

#include "cmath"
#include "unordered_map"

using namespace std;


class Solution {
    int mod = pow(10, 9) + 7;
    vector<vector<int>> dp;
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return (((countBeginWith(n, 'a') + countBeginWith(n, 'e')) % mod +
                 (countBeginWith(n, 'i') + countBeginWith(n, 'o')) % mod) % mod + countBeginWith(n, 'u')) %
               mod;
    }

    int countBeginWith(int n, char c,vector<vector<int>> &dp) {
        if (n == 1) return 1;
        switch (c) {
            case 'a':
                if (eMAP.count(n - 1)) return eMAP[n - 1];
                return eMAP[n - 1] = countBeginWith(n - 1, 'e') % mod;
            case 'e':
                return ((aMAP.count(n - 1) == 0 ? (aMAP[n - 1] = countBeginWith(n - 1, 'a') % mod) :
                         aMAP[n - 1]) +
                        iMAP.count(n - 1) == 0 ? (iMAP[n - 1] = countBeginWith(n - 1, 'i') % mod) :
                        iMAP[n - 1]) % mod;
            case 'i':
                return (((aMAP.count(n - 1) == 0 ? (aMAP[n - 1] = countBeginWith(n - 1, 'a') % mod) :
                          aMAP[n - 1]) +
                         eMAP.count(n - 1) == 0 ? (eMAP[n - 1] = countBeginWith(n - 1, 'e') % mod) :
                         eMAP[n - 1]) % mod +
                        ((oMAP.count(n - 1) == 0 ? (oMAP[n - 1] = countBeginWith(n - 1, 'o') % mod) :
                          oMAP[n - 1]) +
                         uMAP.count(n - 1) == 0 ? (uMAP[n - 1] = countBeginWith(n - 1, 'u') % mod) :
                         uMAP[n - 1]) % mod) % mod;
            case 'o':
                return ((iMAP.count(n - 1) == 0 ? (iMAP[n - 1] = countBeginWith(n - 1, 'i') % mod) :
                         iMAP[n - 1]) +
                        uMAP.count(n - 1) == 0 ? (uMAP[n - 1] = countBeginWith(n - 1, 'u') % mod) :
                        uMAP[n - 1]) % mod;
            case 'u':
                return aMAP.count(n - 1) == 0 ? (aMAP[n - 1] = countBeginWith(n - 1, 'a') % mod) :
                       aMAP[n - 1];
        }
        return -1;
    }
};

#endif //HOT100_1220_H
