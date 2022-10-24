//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_318_H
#define HOT100_318_H

#endif //HOT100_318_H

#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int maxProduct(vector <string> &words) {
        unordered_map<int,int> memo;
        int product=0;
        for (int i = 0; i < words.size(); ++i) {
            int temp=state(words[i]);
            memo[temp]= max(memo[temp],(int)words[i].size());
        }
        auto p=memo.begin(),q=p;
        while (p!=memo.end()){
            unordered_map<int,int>::iterator temp=p;
            q=++p;
            p=temp;
            while (q!=memo.end()){
                if(((*p).first&(*q).first)==0) product= max(product,(*p).second*(*q).second);
                q++;
            }
            p++;
        }
        return product;
    }
    int state(string &word){
        int x=0;
        for (const auto &item: word) {
            x|=1<<(item-'a');
        }
        return x;
    }
};