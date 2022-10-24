//
// Created by 17336 on 2022/4/13.
//

#ifndef HOT100_460_H
#define HOT100_460_H

#include <unordered_map>

using namespace std;

class lnode {
public:
    int key,val, count = 1;
    lnode *next = nullptr, *pre = nullptr;

    lnode(int a,int b) : key(a),val(b) {

    }

    lnode(int a, int b,int c) : key(a), val(b),count(c) {}
};

class LFUCache {
    int cap, cur;
    lnode *head = new lnode(-1, -1,0);
    //根据key获取结点
    unordered_map<int, lnode *> nodes;
    //获取所有count中最后一个结点(最新插入的一个)
    unordered_map<int, lnode *> counts;
private:
    //k->count++后移动结点位置
    void updateCount(lnode *k) {
        int kc = k->count;
        //如果移动前k为count=kc尾结点，更新k后同时更新counts[kc]
        if (counts[kc] == k) {
            if (k->pre->count == kc)counts[kc] = k->pre;
            else counts.erase(kc);
        }
        ++(k->count);
        ++kc;
        //k的位置不变(++kc后，kc仍然小于下一个结点的count或k为尾结点)
        if (k->next == nullptr || k->next->count > kc) {
            counts[kc] = k;
            return;
        }
        //k从当前位置移出
        k->pre->next = k->next;
        k->next->pre = k->pre;
        lnode *p = counts.count(kc) ? counts[kc] : counts[kc - 1];
        //插入k到count[kc]节点中之后
        k->next = p->next;
        k->pre = p;
        p->next = k;
        if (k->next)
            k->next->pre = k;
        counts[kc] = k;
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        cur = 0;
    }

    int get(int key) {
        if (nodes.count(key) == 0) return -1;
        lnode *k = nodes[key];
        updateCount(k);
        return k->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        //已存在结点，更新value和结点位置
        if (nodes.count(key)) {
            lnode *k = nodes[key];
            k->val = value;
            updateCount(k);
            return;
        }
        //超出容量，删除表头结点
        if (cur == cap) {
            lnode *temp = head->next;
            head->next = temp->next;
            if (head->next)
                head->next->pre = head;
            --cur;
            nodes.erase(temp->key);
            if (counts[temp->count] == temp) counts.erase(temp->count);
            delete temp;
        }
        //插入新节点到表头，并更新位置
        lnode *x = new lnode(key,value, 0);
        nodes[key] = x;
        x->next = head->next;
        x->pre = head;
        head->next = x;
        if (x->next) x->next->pre = x;
        updateCount(x);
        ++cur;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //HOT100_460_H
