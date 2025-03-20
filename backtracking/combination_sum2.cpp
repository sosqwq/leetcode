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
    void backtracking( vector<int> & candidates, int target , int sum , int starIndex,vector<bool>& used){
        if(sum > target) { return ;}
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i= starIndex; i< candidates.size()&& sum + candidates[i] <= target; i++){
            if( i > 0 && candidates[i] == candidates [i-1] && used[i-1] == false){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i+1,used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
        
    }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<bool> used(candidates.size(), false);
            sort(candidates.begin(), candidates.end());
            backtracking(candidates, target, 0,0,used);
            return result;

        }
    };