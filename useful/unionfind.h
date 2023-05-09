//
// Created by le.zhang on 2023/5/9.
//

#ifndef HOT100_UNIONFIND_H
#define HOT100_UNIONFIND_H

#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int max_size) : parent(max_size), rank(max_size) {
        // 初始化每一个元素的根节点都为自身
        for (int i = 0; i < max_size; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // 找节点x的根节点
    int find(int x) {
        if(parent[x] == x) return x;
        int p = find(parent[x]);
        // 路径压缩
        parent[x]=p;
        return p;
    }

    //合并x1、x2所在集合
    void union2(int x1, int x2) {
        int p1= find(x1),p2= find(x2);
        if(rank[p1] < rank[p2]) {
            parent[p1] = parent[p2];
        }
        else {
            parent[p2] = parent[p1];
            if(rank[p1]==rank[p2]) ++rank[p1];
        }
        parent[find(x1)] = find(x2);
    }

    // 判断两个元素是否属于同一个集合
    bool is_same(int e1, int e2) {
        return find(e1) == find(e2);
    }
};

#endif //HOT100_UNIONFIND_H
