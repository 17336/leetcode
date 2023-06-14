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
#include "2684.h"

using namespace std;

vector<string> res;

int main() {
    std::vector<string> a{"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"}, b{"10:00", "10:40", "11:00",
                                                                                           "09:00", "11:00", "13:00",
                                                                             "15:00"};
    vector<vector<int>> grid{{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}},grid1{{4,9,11}};
    std::cout<<Solution().maxMoves(grid1);
}
