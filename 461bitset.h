//
// Created by 17336 on 2021/11/4.
//

#ifndef HOT100_461BITSET_H
#define HOT100_461BITSET_H

#endif //HOT100_461BITSET_H

#include "bitset"
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> b(x^y);
        return b.count();
    }
};