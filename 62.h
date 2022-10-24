//
// Created by 17336 on 2022/2/25.
//

#ifndef HOT100_62_H
#define HOT100_62_H

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    //unordered_map<int, int> map;
    vector<vector<int>> map;
public:
    int uniquePaths(int m, int n) {
        map.resize(m+1,vector<int>(n+1,0));
//        int key;
//        if (m < n)key = n * 100 + m;
//        else key = m * 100 + n;
//        if(map.count(key)) return map[key];
//        return map[key]= uniquePaths(m-1,n)+ uniquePaths(m,n-1);
        return track(m,n);
    }
    int track(int m,int n){
        if(n==1||m==1) return 1;
        if(map[m][n]||map[m][n]) return map[n][m];
        return map[n][m]= track(m-1,n)+ track(m,n-1);
    }
};

#endif //HOT100_62_H
