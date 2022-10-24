//
// Created by 17336 on 2022/6/28.
//

#ifndef HOT100_DP_MATRIXMULTI_H
#define HOT100_DP_MATRIXMULTI_H

#include <vector>

using namespace std;

/**
 *
 * @param p [p0...pn]对应A0*A1*...An-1
 * @return
 */
int matrixOrder(vector<int> &p){
    int len=p.size();
    vector<vector<int>> cost(len,vector<int>(len,0)),best(len,vector<int>(len));
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i+1; j < len; ++j) {
            int k=
        }
    }
}

#endif //HOT100_DP_MATRIXMULTI_H
