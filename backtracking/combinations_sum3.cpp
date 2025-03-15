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
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k, int n,int sum,int startIndex){
        if(sum> n) return;
        if(path.size() == k){
            if(sum == n){
                result.push_back(path);
                return;
            }
        }

        for(int i = startIndex; i<= 9; i++){
            sum += i;
            path.push_back(i);
            backtracking(k,n,sum,i+1);
            sum -= i;
            path.pop_back();
        }
    }
        vector<vector<int>> combinationSum3(int k, int n) {
            backtracking(k,n,0,1);
            return result;
        }
    };