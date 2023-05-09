//
// Created by le.zhang on 2023/5/9.
//

#ifndef HOT100_1061BEST_H
#define HOT100_1061BEST_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int len=s1.size();
        UnionFind u;
        for (int i = 0; i < len; ++i) {
            u.union2(s1[i]-'a',s2[i]-'a');
        }
        string res;
        for (auto c: baseStr) {
            res.push_back(u.find(c-'a')+'a');
        }
        return res;
    }
    class UnionFind {
    public:
        vector<int> pre;
        UnionFind():pre(26) {
            for (int i = 0; i < 26; ++i) {
                pre[i]=i;
            }
        }
        int find(int x) {
            if(pre[x]==x) return x;
            int root=find(pre[x]);
            pre[x]=root;
            return root;
        }
        void union2(int x1,int x2) {
            if(x1==x2) return;
            int p1= find(x1);
            int p2= find(x2);
            if(p1<p2) {
                pre[p2]=p1;
            }
            else {
                pre[p1]=p2;
            }
        }
    };
};

#endif //HOT100_1061BEST_H
