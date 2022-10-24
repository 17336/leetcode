//
// Created by 17336 on 2022/1/14.
//

#ifndef HOT100_373_H
#define HOT100_373_H

#include "vector"

using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        res.push_back({nums1[0],nums2[0]});
        int a1=0,b1=1,a2=0,b2=1;
        int len1=nums1.size(),len2=nums2.size();
        for (int i = 0; i < k-1; ++i) {
            if(b1>=len2){
                ++a1;
                b1=a2+1;
                if(b1>=len2) {
                    for (int i = b; i < k; ++i) {
                        res.push_back({nums1[a], nums2[i]});
                    }
                    func(nums2,nums1,a2,b2,b2-1+k-i);
                    return res;
                }
            }
            if(b2>=len1){
                ++a2;
                b2=a1+1;
                if(b1>=len2) {
                    func(nums1,nums2,a1,b2,b1-1+k-i);
                    return res;
                }
            }
            if(nums1[a1]+nums2[b1]<nums2[a2]+nums1[b2]){
                res.push_back({nums1[a1],nums2[b1]});
                ++b1;
            }
            else{
                res.push_back({nums2[a2],nums1[b2]});
                ++b2;
            }
        }
        return res;
    }
    void func(vector<int> &nums1,vector<int> &nums2,int a,int b,int k){

    }
};

#endif //HOT100_373_H
