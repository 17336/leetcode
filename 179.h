//
// Created by 17336 on 2022/4/9.
//

#ifndef HOT100_179_H
#define HOT100_179_H

#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<int> count(10,0);
        for (const auto &item: nums) {
            ++count[getHighestDigit(item)];
        }
        auto p = [&](const int a, const int b) -> bool {
            string sa= to_string(a),sb=to_string(b);
            int i=0;
            while (i<sa.size()&&i<sb.size()){
                if(sa[i]<sb[i]) return true;
                if(sa[i]>sb[i]) return false;
                ++i;
            }
            if(sa.size()==sb.size()) return false;
            if(i==sa.size()){
                if(sb[i]>sb[i-1]) return true;
//                int bNext=sb[i];
//                while (++bNext<sb[i-1]){
//                    if(count[bNext]) return false;
//                }
                return false;
            }
            if(sa[i]>sa[i-1]) return false;
//            int aNext=sa[i];
//            while (++aNext<sa[i-1]){
//                if(count[aNext]) return true;
//            }
            return true;
        };
        priority_queue<int, vector<int>, decltype(p)> heap(p);
        for (const auto &num: nums) {
            heap.push(num);
        }
        string res;
        while (!heap.empty()){
            res.append(to_string(heap.top()));
            --count[getHighestDigit(heap.top())];
            heap.pop();
        }
        return res;
    }

    int getHighestDigit(int a){
        if(a>=100000000) a/=100000000;
        if(a>=10000) a/=10000;
        if(a>=100) a/=100;
        if(a>=10) a/=10;
        return a;
    }
};

#endif //HOT100_179_H
