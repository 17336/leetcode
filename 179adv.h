//
// Created by 17336 on 2022/4/9.
//

#ifndef HOT100_179ADV_H
#define HOT100_179ADV_H

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(),nums.end(),[](const int a,const int b){
            string sa= to_string(a),sb= to_string(b);
           return (sa+sb)>(sb+sa);
        });
        string res;
        for (const auto &item: nums) {
            res+= to_string(item);
        }
        if(res[0]=='0') return "0";
        return res;
    }
};

#endif //HOT100_179ADV_H
