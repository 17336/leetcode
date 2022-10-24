//
// Created by 17336 on 2021/11/16.
//

#ifndef HOT100_391_H
#define HOT100_391_H

#endif //HOT100_391_H

#include "vector"
#include "unordered_set"
#include "set"
using namespace std;

struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2> &a)const{
        return hash<int>()(a.first)^hash<int>()(a.second);
    }
};
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //这里选set不选unordered_set是因为自定义的pair_hash冲突次数太多，性能足足差了四倍
        set<pair<int,int>> endpoint;
        int sumArea=0;
        for (const auto &rectangle: rectangles) {
            sumArea+=(rectangle[2]-rectangle[0])*(rectangle[3]-rectangle[1]);
            pair<int,int> temp{rectangle[0],rectangle[1]};
            //矩形四个端点如果出现过就代表是偶数次，删除；没出现过就是奇数次，插入
            if(endpoint.count(temp)) endpoint.erase(temp);
            else endpoint.insert(temp);
            temp={rectangle[2],rectangle[3]};
            if(endpoint.count(temp)) endpoint.erase(temp);
            else endpoint.insert(temp);
            temp={rectangle[0],rectangle[3]};
            if(endpoint.count(temp)) endpoint.erase(temp);
            else endpoint.insert(temp);
            temp={rectangle[2],rectangle[1]};
            if(endpoint.count(temp)) endpoint.erase(temp);
            else endpoint.insert(temp);
        }
        //如果只剩四个端点，就检查面积是否有重叠
        if(endpoint.size()==4) {
            set<pair<int,int>>::iterator b=endpoint.begin();
            pair<int,int> x= *(b++);
            while (!(b->first!=x.first&&b->second!=x.second)) b++;
            pair<int,int> y=*b;
            if(abs(x.first-y.first)* abs(x.second-y.second)==sumArea)return true;
        }
        return false;
    }
};