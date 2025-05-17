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
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool> (s.size(), false));
        if(s.size() == 1) return 1;
        int count = 0;
        dp[s.size()-1][0] = true;
        for(int i = s.size()-1; i>= 0;i--){
            for(int j = i; j< s.size(); j++){
                if(s[j] == s[i]){
                    if(j-i <= 1){
                        dp[i][j] = true;
                        count++;
                    }
                    else if( dp[i+1][j-1]){
                        count ++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return count;
    }
};