//
// Created by 17336 on 2021/11/8.
//

#ifndef HOT100_299_H
#define HOT100_299_H

#endif //HOT100_299_H

#include "string"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int countSr[10] = {0}, countGs[10] = {0};
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                a++;
                continue;
            }
            countGs[guess[i] - '0']++;
            countSr[secret[i] - '0']++;
            if (countSr[guess[i] - '0']) {
                b++;
                countSr[guess[i] - '0']--;
                countGs[guess[i] - '0']--;
            }
            if(countGs[secret[i]-'0']){
                b++;
                countGs[secret[i] - '0']--;
                countSr[secret[i] - '0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};