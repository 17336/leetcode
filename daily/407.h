//
// Created by 17336 on 2021/11/3.
//

#ifndef HOT100_407_H
#define HOT100_407_H

#endif //HOT100_407_H

#include "vector"
#include "stack"
#include "queue"
using namespace std;

//用于小根堆的排序算法
struct my_greater{
    bool operator()(const vector<int> &a,const vector<int> &b){
        return a.front()>b.front();
    }
};


class Solution {
    //上下左右各走一步
    int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    //水面高度
    vector<vector<int>> water{};
public:
    int trapRainWater(vector <vector<int>> &heightMap) {
        //只有边界，存不住水
        if(heightMap.size()==2||heightMap[0].size()==2) return 0;
        //小根堆
        priority_queue<vector<int>,vector<vector<int>>,my_greater> heap;
        int m=heightMap.size(),n=heightMap[0].size(),count=m*n;
        for (int i = 0; i < heightMap.size(); ++i) {
            water.push_back({});
            for (int j = 0; j < heightMap[0].size(); ++j) {
                if(i==0||j==0||i==heightMap.size()-1||j==heightMap[0].size()-1) {
                    water.back().push_back(heightMap[i][j]);
                    heap.push({water[i][j],i,j});
                    count--;
                }
                else water.back().push_back(-1);
            }
        }
        int sum=0;
        while (count!=0){
            vector<int> temp=heap.top();
            pair<int,int> next= nextN(temp[1],temp[2]);
            if(next.first==-1&&next.second==-1) {
                heap.pop();
                continue;
            }
            else{
                int margin_height=temp[0];
                water[next.first][next.second]= max(temp[0],heightMap[next.first][next.second]);
                heap.push({water[next.first][next.second],next.first,next.second});
                sum+=water[next.first][next.second]-heightMap[next.first][next.second];
                count--;
            }
        }
        return sum;
    }
    pair<int,int> nextN(int i,int j){
        for (int k = 0; k < 4; ++k) {
            int newx = i +step[k][0],newy=j+step[k][1];
            if(newx<0||newx>=water.size()||newy<0||newy>=water[0].size()) continue;
            else if(water[newx][newy]==-1) return {newx,newy};
        }
        return {-1,-1};
    }
};