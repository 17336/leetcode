//
// Created by ByteDance on 2023/2/7.
//

#ifndef HOT100_1604_H
#define HOT100_1604_H

#include <vector>
#include <string>
#include <map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
        vector<string> res;
        map<string, vector<int>> name_uses;
        int len = keyName.size();
        for (int i = 0; i < len; ++i) {
            name_uses[keyName[i]].push_back(
                    (keyTime[i][0] - '0') * 600 + (keyTime[i][1] - '0') * 60 + (keyTime[i][3] - '0') * 10 +
                    keyTime[i][4] - '0');
        }
        for (auto &item:name_uses) {
            int n=item.second.size();
            quick_sort(item.second,0,n-1);
            for (int i = 0; i < n-2; ++i) {
                if(item.second[i+2]-item.second[i]<=60){
                    res.push_back(item.first);
                    break;
                }
            }
        }
        return res;

    }
    void quick_sort(vector<int> &nums,int l,int r) {
        if(l<r){
            int p= partition(nums,l,r);
            quick_sort(nums,l,p-1);
            quick_sort(nums,p+1,r);
        }
    }

    int partition(vector<int> &nums, int l, int r) {
        if (l==r) return l;
        int pilot = nums[l];
        while (l<r) {
            while (l<r&&nums[r]>=pilot) --r;
            nums[l] = nums[r];
            while (l<r&&nums[l]<=pilot) ++l;
            nums[r]=nums[l];
        }
        nums[l] =pilot;
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_1604_H
