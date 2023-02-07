//
// Created by ByteDance on 2023/1/9.
//

#include <vector>

#ifndef HOT100_1806_H
#define HOT100_1806_H

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reinitializePermutation(int n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i]=i;
        }
        int res=0;
        do {
            std::vector<int> temp(n);
            for (int i = 0; i < n; ++i) {
                if(i%2)
                    temp[i] = arr[n / 2 + (i - 1) / 2];
                else
                    temp[i] = arr[i/2];
            }
            arr.swap(temp);
            ++res;
        }while(!isReinitial(arr));
        return res;
    }
    bool isReinitial(std::vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if(arr[i]!=i) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1806_H
