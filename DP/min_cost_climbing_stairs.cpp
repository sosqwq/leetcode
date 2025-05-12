#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> result(cost.size()+1);
        result[1] = 0;
        result[0] = 0;
        if(cost.size() < 2) return 0;

        for(int i = 2; i<= cost.size();i++){
            result[i] = min(result[i-1]+cost[i-1],result[i-2]+ cost[i-2]);
        }
        return result[cost.size()];
    }
};