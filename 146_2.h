//
// Created by 17336 on 2022/2/27.
//

#ifndef HOT100_146_2_H
#define HOT100_146_2_H

#include <list>
#include <unordered_map>

class LRUCache {
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> map;
    std::list<int> lst;
    int cap;
public:
    LRUCache(int capacity) : cap(capacity) {

    }

    int get(int key) {
        if(!map.count(key)) return -1;
        int value=map[key].first;
        lst.erase(map[key].second);
        map.erase(key);
        map[key].first = value;
        lst.push_front(key);
        map[key].second = lst.begin();
        return value;
    }

    void put(int key, int value) {
        if (!map.count(key) && lst.size() >= cap) {
            map.erase(lst.back());
            lst.pop_back();
        } else if(map.count(key)){
            lst.erase(map[key].second);
            map.erase(key);
        }
        map[key].first = value;
        lst.push_front(key);
        map[key].second = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //HOT100_146_2_H
