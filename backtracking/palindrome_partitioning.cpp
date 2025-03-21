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
    vector<string> path;
    vector<vector<string>> result;
    void backtracking(const string&  s,int starIndex){
        if(starIndex >= s.size()){
            result.push_back(path);
        }
        for(int i= starIndex;i<s.size();i++){
            if(isPalindrome(s,starIndex,i)){
                string str = s.substr(starIndex, i- starIndex + 1);
                path.push_back(str);
            }
            else {                                // 不是回文，跳过
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string & s , int start, int end){
        for(int i = start, j = end;i < j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
        vector<vector<string>> partition(string s) {
            backtracking(s,0);
            return result;
        }
    };