//
// Created by 17336 on 2021/11/9.
//

#ifndef HOT100_488_H
#define HOT100_488_H

#endif //HOT100_488_H

#include "string"
#include "unordered_map"
#include "forward_list"
#include "climits"
using namespace std;

typedef struct flist{
public:
    char c;
    int count;
    flist *next;
    flist *last;
    flist(char a,int b):c(a),count(b),next(nullptr),last(nullptr){}
    bool insertList(flist *begin,flist *end){
        auto temp=this->next;
        begin->last=this;
        end->next=temp;
        this->next=begin;
        temp->last=end;
    }
    flist *erase(){
        flist *x=this->next;
        this->next= this->next->next;
        this->next->last= this;
        return x;
    }
}flist;
class Solution {
    unordered_map<char,int> ha;
    flist *list=new flist('Z',-1);
public:
    int findMinStep(string board, string hand) {
        ha=unordered_map<char,int>{{'R',0},{'Y',0},{'B',0},{'G',0},{'W',0}};
        for (const auto &item: hand) {
            ha[item]++;
        }
        flist *p= this->list;
        for (const auto &item: board) {
            if(p->c!=item){
                flist *x=new flist(item,1);
                p->insertList(x,x);
            }
            else p->count++;
            p=p->next;
        }
    }
    int backtrack(){
        int min=INT_MAX;
        auto p=list;
        while (p->next!= nullptr){
            if(ha[p->next->c]+p->next->count>=3){
                ha[p->next->c]-=3-p->next->count;
                flist *temp=p->next->erase();
                flist *a=p,*b=p->next;
                while (a->c!='C'&&b!= nullptr&&a->c==b->c){

                }
            }
        }
    }
};