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
    vector<int> set;
    vector<vector<int>> result;

    void backtracking (vector<int> & nums , int index, vector<bool> used){
        result.push_back(set);
        if(index >= nums.size()){
            return;
        }
        for(int i = index; i< nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            set.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1,used);
            set.pop_back();
            used[i] = false;
        }
    }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<bool> used(nums.size(), false);
            sort(nums.begin(),nums.end());
            backtracking (nums, 0, used);

            return result;
        }
    };