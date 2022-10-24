//
// Created by 17336 on 2022/6/4.
//

#ifndef HOT100_929_H
#define HOT100_929_H

#include "basi.h"

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> set;
        for (const auto &email: emails) {
            string e;
            int i = 0;
            while (email[i] != '+' && email[i] != '@') {
                if (email[i] != '.') e.push_back(email[i]);
                ++i;
            }
            while (email[i]!='@') ++i;
            e.append(email.substr(i));
            set.insert(e);
        }
        return set.size();
    }
};

#endif //HOT100_929_H
