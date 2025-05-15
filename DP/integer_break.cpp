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
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i  = 3; i<= n; i++){
            for(int j = 1; j<=i/2; j++){
                dp[i] = max(dp[i], max((i-j)*j, dp[i-j] *j));
            }
        }
        return dp[n];
    }
};