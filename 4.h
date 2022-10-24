//
// Created by 17336 on 2021/11/9.
//

#ifndef HOT100_4_H
#define HOT100_4_H

#endif //HOT100_4_H

#include "vector"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=-1;
        vector<int> &larr=nums1.size()>nums2.size()?nums1:nums2;
        vector<int> &sarr=nums1.size()>nums2.size()?nums2:nums1;
        auto p=sarr.begin(),q=larr.begin();
        int target=(nums1.size()+nums2.size()-1)/2;
        while (x!=target){
            int temp= next(p,q,sarr,larr);
            x++;
            if(x==target){
                if((nums1.size()+nums2.size())%2) return temp;
                else return (temp*1.0+ next(p,q,sarr,larr))/2;
            }
        }
        return -1;
    }
    int next(vector<int>::iterator &p,vector<int>::iterator &q,vector<int> &sarr,vector<int> &larr){
        if(p==sarr.end()) return *(q++);
        if(q==larr.end()) return *(p++);
        if(*p<*q) return *(p++);
        return *(q++);
    }
};