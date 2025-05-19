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
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));
        int start = 0;
        int maxlen = 0;
        for(int i= s.size()-1  ; i >= 0; i--){
            for(int j = i; j<s.size(); j++){
                if(s[i] == s[j]){
                    if(j-i<=1||dp[i+1][j-1]){
                        dp[i][j] = true;
                        if( j-i+1 > maxlen){
                        maxlen = j -i +1;
                        start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};