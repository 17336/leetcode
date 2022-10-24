//
// Created by 17336 on 2022/3/15.
//

#ifndef HOT100_208_H
#define HOT100_208_H

#include <string>
#include <vector>

using namespace std;

class Trie {
    vector<Trie *> next;
    bool isEnd;
public:
    Trie() : next(26, nullptr), isEnd(false) {

    }

    virtual ~Trie() {
        Trie *p = this;
        for (int i = 0; i < 26; ++i) {
            delete p->next[i];
        }
    }

    void insert(string word) {
        Trie *p = this;
        for (const auto &item: word) {
            if (p->next[item - 'a'] == nullptr) {
                p->next[item - 'a'] = new Trie();
            }
            p = p->next[item - 'a'];
        }
        p->isEnd = true;
    }

    bool search(string word) {
        Trie *p = this;
        for (const auto &item: word) {
            if (p->next[item - 'a'] == nullptr) return false;
            p = p->next[item - 'a'];
        }
        return p->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *p = this;
        for (const auto &item: prefix) {
            if (p->next[item - 'a'] == nullptr) return false;
            p = p->next[item - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //HOT100_208_H
