//
// Created by 17336 on 2021/12/6.
//

#ifndef HOT100_146_H
#define HOT100_146_H

#include "unordered_map"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *last;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr), last(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next), last(nullptr) {}

    ListNode(int x, ListNode *next, ListNode *last) : val(x), next(next), last(last) {}

    static void erase(ListNode *p) {
        p->last->next = p->next;
        if (p->next)p->next->last = p->last;
    }

    static ListNode *insert(ListNode *rear, ListNode *p) {
        rear->next = p;
        p->last = rear;
        p->next = nullptr;
        return p;
    }
};

class LRUCache {
    int capacity;
    ListNode *head;
    ListNode *rear;
    unordered_map<int, pair<int, ListNode *>> map;
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new ListNode();
        rear = head;
    }

    int get(int key) {
        if (map.count(key) == 0) return -1;
        if (rear->val != key) {
            ListNode::erase(map[key].second);
            rear = ListNode::insert(rear, map[key].second);
        }
        return map[key].first;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            map[key].first = value;
            if (rear->val != key) {
                ListNode::erase(map[key].second);
                ListNode::insert(rear, map[key].second);
                rear = map[key].second;
            }
        } else if (map.size() < capacity) {
            ListNode *p = new ListNode(key);
            map[key] = {value, p};
            rear = ListNode::insert(rear, p);
        } else {
            ListNode *p = new ListNode(key);
            map[key] = {value, p};
            map.erase(head->next->val);
            ListNode::erase(head->next);
            if (head->next == nullptr) rear = head;
            rear = ListNode::insert(rear, p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //HOT100_146_H
