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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,0)); //二维数组,初始化为0
        for(int i = 0; i< m;i++) dp[i][0] = 1;
        for(int j = 0; j< n; j++) dp[0][j] = 1;
        for(int i = 1; i< m; i++){
            for(int j= 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};