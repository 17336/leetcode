//
// Created by 17336 on 2022/6/6.
//

#ifndef HOT100_732_H
#define HOT100_732_H

#include <map>

using namespace std;

class MyCalendarThree {
    map<int, int> arrange;
    int m;
public:
    MyCalendarThree() : m(0) {

    }

    int book(int start, int end) {
        auto beg = arrange.lower_bound(start);
        if(beg==arrange.end()){
            arrange.emplace(start,1);
            arrange.emplace(end,0);
            m= max(m,1);
            return m;
        }
        int last;
        if (beg->first != start) {
            if (beg == arrange.begin()) {
                arrange.emplace(start, 1);
                m= max(m,1);
                last=1;
            } else {
                --beg;
                arrange.emplace(start, beg->second+1);
                m= max(m,beg->second+1);
                last=beg->second+1;
                ++beg;
                ++beg;
            }
        }
        while (beg!=arrange.end()&&beg->first < end) {
            ++beg->second;
            last=beg->second;
            m= max(m,last);
            ++beg;
        }
        arrange.emplace(end,last-1);
        return m;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

#endif //HOT100_732_H
