//
// Created by 17336 on 2021/12/9.
//

#ifndef HOT100_794_H
#define HOT100_794_H

#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string> &board) {
        int countx = 0, counto = 0;
        char win = 'P';
        for (const auto &item: board) {
            for (const auto &c: item) {
                if (c == 'X') countx++;
                else if (c == 'O') counto++;
            }
        }
        if (countx - counto != 0 && countx - counto != 1) return false;
        if(board[0][0]!=' '&&board[0][0]==board[1][1]&&board[0][0]==board[2][2]) win=board[0][0];
        if(board[0][2]!=' '&&board[0][2]==board[1][1]&&board[2][0]==board[1][1]) win=board[0][2];
        if(win=='X'&&countx==counto) return false;
        if(win=='O'&&countx>counto) return false;
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] != ' ' && board[1][i] == board[0][i] && board[1][i] == board[2][i]) {
                if (win != 'P' && win != board[0][i]) return false;
                win = board[0][i];
                if(win=='X'&&countx==counto) return false;
                if(win=='O'&&countx>counto) return false;
            }
        }
        if (win != 'P') return true;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][1] == board[i][0] && board[i][1] == board[i][2]) {
                if (win != 'P' && win != board[i][0]) return false;
                win = board[i][0];
                if(win=='X'&&countx==counto) return false;
                if(win=='O'&&countx>counto) return false;
            }
        }
        return true;
    }
};

#endif //HOT100_794_H
