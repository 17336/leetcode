//
// Created by 17336 on 2021/11/24.
//

#ifndef HOT100_423_H
#define HOT100_423_H

#include "string"
#include "vector"
//zero one two three four five six seven eight nine

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26,0);
        vector<int> nums(10,0);
        for (const auto &item: s) {
            if(item=='z') {
                nums[0]++;
                count['e'-'a']--;
                count['r'-'a']--;
                count['o'-'a']--;
            }
            else if(item=='g'){
                nums[8]++;
                count['e'-'a']--;
                count['i'-'a']--;
                count['h'-'a']--;
                count['t'-'a']--;
            }
            else if(item=='x'){
                nums[6]++;
                count['s'-'a']--;
                count['i'-'a']--;
            }
            else if(item=='u'){
                nums[4]++;
                count['f'-'a']--;
                count['o'-'a']--;
                count['r'-'a']--;
            }
            else if(item=='w'){
                nums[2]++;
                count['t'-'a']--;
                count['o'-'a']--;

            }
            else count[item-'a']++;
        }
        nums[1]=count['o'-'a'];
        nums[3]=count['t'-'a'];
        nums[5]=count['f'-'a'];
        count['i'-'a']-=nums[5];
        nums[7]=count['s'-'a'];
        nums[9]=count['i'-'a'];
        string res;
        for (int i = 0; i < 10; ++i) {
            res.insert(res.end(),nums[i],i+'0');
        }
        return res;
    }
};

#endif //HOT100_423_H
