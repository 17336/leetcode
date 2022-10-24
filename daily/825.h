//
// Created by 17336 on 2021/12/27.
//

#ifndef HOT100_825_H
#define HOT100_825_H

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        sort(ages.begin(), ages.end());
        int sum=0,last=0;
        int sameCount=0;
        int i = 0;
        for (; i < ages.size(); ++i) {
            if(i>0&&ages[i]==ages[i-1])++sameCount;
            else{
                if(i>0&&ages[i-1]>=15)sum+=(sameCount+1)*sameCount/2;
                sameCount=0;
            }
            last= bSearch(ages,(int)(0.5*ages[i]+7),last,i-1);
            sum+=(i-last);
        }
        return sum+((i>0&&ages[i-1]>=15)?(sameCount+1)*sameCount/2:0);
    }

    int bSearch(vector<int> &ages,int lowest,int low,int high) {
        int res=high+1;
        while (low<=high){
            int mid=(low+high)/2;
            if(ages[mid]<=lowest){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};

#endif //HOT100_825_H
