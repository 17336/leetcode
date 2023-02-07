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
#include "1604.h"

using namespace std;

vector<string> res;

int main() {
    std::vector<string> a{"daniel","daniel","daniel","luis","luis","luis","luis"},b{"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    Solution().alertNames(a,b);
}
