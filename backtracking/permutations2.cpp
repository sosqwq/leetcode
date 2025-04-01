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
    void backtracking (vector<int> & nums, vector<bool> used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0;i< nums.size();i++){
            if(i>0&& nums[i] == nums[i-1] && used [i-1] == false){
                continue;
            }
            
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;

    }
};