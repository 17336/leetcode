//
// Created by 17336 on 2022/4/4.
//

#ifndef HOT100_165_H
#define HOT100_165_H

#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while (i<version1.size()||j<version2.size()){
            int n1=0,n2=0;
            while (i<version1.size()&&version1[i]!='.') n1=n1*10+(version1[i++]-'0');
            while (j<version2.size()&&version2[j]!='.') n2=n2*10+(version2[j++]-'0');
            if (n1>n2) return 1;
            if (n1<n2) return -1;
            ++i;
            ++j;
        }
        return 0;
    }
};

#endif //HOT100_165_H
