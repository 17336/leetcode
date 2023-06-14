//
// Created by le.zhang on 2023/5/17.
//

#ifndef HOT100_2682_H
#define HOT100_2682_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> visited(n+1,0);
        int i=1;
        int p=1;
        while (visited[i]==0) {
            visited[i]=1;
            i=(i-1+p*k)%n+1;
            ++p;
        }
        vector<int> res;
        for (int j = 1; j <= n; ++j) {
            if(visited[j]==0) res.push_back(j);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_2682_H
