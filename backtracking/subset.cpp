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
    vector<vector<int>> result;
    vector<int> set;
    void backtracking (vector<int> & nums, int index){
        result.push_back(set);
        if(index >= nums.size()){
            return;
        }
        for(int i = index; i< nums.size(); i++){
            set.push_back(nums[i]);
            backtracking(nums,i+1);
            set.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};