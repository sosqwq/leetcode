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
    int climbStairs(int n) {
        if(n<= 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];

        }
        return  dp[n];
    }
};
