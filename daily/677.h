//
// Created by 17336 on 2021/11/14.
//

#ifndef HOT100_677_H
#define HOT100_677_H

#endif //HOT100_677_H
#include "string"

using namespace std;

class MapSum {
    MapSum *next[26]={nullptr};
    int value=0;
public:
    MapSum() {

    }
    MapSum(int val):value(val){

    }
    void insert(string key, int val) {
        MapSum *p=this;
        for (const auto &item: key) {
            if(p->next[item-'a']== nullptr) p->next[item-'a']=new MapSum();
            p=p->next[item-'a'];
        }
        p->value=val;
    }

    int sum(string prefix) {
        int i=0;
        MapSum *p=this;
        for (; i < prefix.size(); ++i) {
            p=p->next[prefix[i]-'a'];
            if(p== nullptr) break;
        }
        if(p== nullptr) return 0;
        return backtrack(p);
    }
    int backtrack(MapSum *p){
        int sum=p->value;
        for (int i = 0; i < 26; ++i) {
            if(p->next[i]) {
                sum+=backtrack(p->next[i]);
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */