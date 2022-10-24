//
// Created by 17336 on 2021/12/29.
//

#ifndef HOT100_1078_H
#define HOT100_1078_H

#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        //上一个单词的equalWhich结果
        pair<bool, bool> last{false, false};
        //下一个单词要不要加入res
        bool isPush= false;
        for (int i = 0; i < text.size(); ++i) {
            pair<bool, bool> now{false, false};
            int temp = equalWhich(text, i, first, second, now);
            while (temp<text.size()&&text[temp]!=' ')temp++;
            if(isPush) res.push_back(text.substr(i,temp-i));
            if (now.second && last.first) isPush= true;
            else isPush= false;
            last=now;
            i=temp;
        }
        return res;
    }
    //判断text中begin开头的单词是否等于first、second
    int equalWhich(string &text, int begin, string &first, string &second, pair<bool, bool> &now) {
        int i = begin, res;
        while (i < text.size() && i - begin < first.size() && text[i] != ' ' && text[i] == first[i - begin])i++;
        if (text[i] == ' ' && i - begin == first.size()) now.first = true;
        res = i;
        i = begin;
        while (i < text.size() && i - begin < second.size() && text[i] != ' ' && text[i] == second[i - begin])i++;
        if (text[i] == ' ' && i - begin == second.size()) now.second = true;
        res = max(res, i);
        return res;
    }
};

#endif //HOT100_1078_H
