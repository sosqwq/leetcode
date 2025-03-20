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
    void backtracking(vector<int> & candidate,int target,int sum, int starIndex){

        if(target < sum){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }

        for(int i= starIndex; i< candidate.size() &&sum + candidate[i] <= target; i++){
            sum += candidate[i];
            path.push_back(candidate[i]);
            backtracking(candidate,target,sum,i);
            path.pop_back();
            sum -= candidate[i];
        }
    }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            backtracking(candidates,target,0,0);
            return result;
        }
    };