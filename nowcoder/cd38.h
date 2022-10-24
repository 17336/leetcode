//
// Created by 17336 on 2022/3/20.
//

#ifndef HOT100_CD38_H
#define HOT100_CD38_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    vector<int> arr1, arr2;
    int len, k;
    cin >> len >> k;
    for (int i = 0; i < len; ++i) {
        int t;
        cin >> t;
        arr1.push_back(t);
    }
    for (int i = 0; i < len; ++i) {
        int t;
        cin >> t;
        arr2.push_back(t);
    }
    unordered_set<int> set;
    auto myless = [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return arr1[a.first] + arr2[a.second] < arr1[b.first] + arr2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myless)> q(myless);
    q.push({len-1,len-1});
    set.insert((len-1)*len+len-1);
    int count=0;
    while (count < k) {
        int v1=q.top().first,v2=q.top().second;
        q.pop();
        cout<<arr1[v1]+arr2[v2]<<' ';
        ++count;
        if(v1>=1&&set.count((v1-1)*len+v2)==0){
            q.push({v1-1,v2});
            set.insert((v1-1)*len+v2);
        }
        if(v2>=1&&set.count(v1*len+v2-1)==0){
            q.push({v1,v2-1});
            set.insert(v1*len+v2-1);
        }
    }
}

#endif //HOT100_CD38_H
