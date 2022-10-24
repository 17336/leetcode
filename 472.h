//
// Created by 17336 on 2021/10/29.
//

#ifndef HOT100_472_H
#define HOT100_472_H

#endif //HOT100_472_H

#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;


class Solution {
    unordered_set<string> set;
    unordered_map<string, bool> memo;//用于记忆化所有已经找过的连接词/非连接词
    Solution *next[26] = {nullptr};//字典树
    bool now_end = false;//字典树某路径是否为一个单词
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        //初始化前缀树
        for (const auto &word: words) {
            insert(word);
            set.insert(word);
        }
        //结果数组res
        vector<string> res;
        //对words中的每一个单词进行判断是否是连接词
        for (const auto &item: words) {
            if(backtrack(item)) res.push_back(item);
        }
        return res;
    }

    //判断word是否是连接词
    bool backtrack(const string &word) {
        if (memo.count(word)) return memo[word];
        //遍历指针
        Solution *p = this;
        for (int i = 0; i < word.size(); i++) {
            //一旦某个单词的某个字母word[i]找不到，那就返回false
            if (p->next[word[i] - 'a'] == nullptr) return false;
            p = p->next[word[i] - 'a'];
            //如果找到连接词的一部分了，试探着判断剩下的能否连接或者已经存在
            //注意在words中已经存在的单词不能简单的直接置为true，必须要由两个以上连接
            if (p->now_end && i != word.size() - 1) {
                string sub = word.substr(i + 1);
                //如果剩下的词  正好在set中存在
                if (set.count(sub) ) {
                    memo[word] = true;
                    return true;
                }
                //如果剩下的词原来判断过
                if(memo.count(sub)){
                    if(memo[sub]){
                        memo[word] = true;
                        return true;
                    }
                    else continue;
                }
                //如果剩下的词是连接词
                if (backtrack(sub)) {
                    memo[word] = true;
                    return true;
                }
                //如果不是连接词，找下一个now_end，并判断now_end剩下的
            }
        }
        memo[word] = false;
        return false;
    }

    //插入一个单词word到前缀树当中
    void insert(const string &word) {
        //遍历指针
        Solution *p = this;
        for (const auto &item: word) {
            if (p->next[item - 'a'] == nullptr) p->next[item - 'a'] = new Solution();
            p = p->next[item - 'a'];
        }
        p->now_end = true;
    }
};