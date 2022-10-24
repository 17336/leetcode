#include <string>
#include <vector>
#include "algorithm"
#include <list>
#include <unordered_map>
#include <iostream>
#include "sorts.h"
#include "test.h"
#include <unistd.h>
//#include "nowcoder/zprintTree.h"
#include "732.h"

using namespace std;

vector<string> res;

int main() {
    vector<int> a{1, 2, 3}, c{3, 4};
    vector<vector<int>> vvi{
            {3, 4},
            {2, 3},
            {1, 2}};
    string s1("hel");
    string s2("hel");
    vector<vector<char>> b{{'A', 'B', 'E'},
                           {'B', 'C', 'D'}};
    MyCalendarThree myCalendarThree;
    myCalendarThree.book(10,20);
    myCalendarThree.book(40,60);
    myCalendarThree.book(10,40);
    myCalendarThree.book(5,15);
    myCalendarThree.book(5,10);
    myCalendarThree.book(25,55);
}
