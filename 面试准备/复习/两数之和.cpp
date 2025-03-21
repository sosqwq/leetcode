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
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> map;

            for(int i=0;i<nums.size();i++){
                int s = target - nums[i];
                auto key = map.find(s);
                if(key != map.end()){
                    return {i,key->second};
                }
                return {};
            }
        }
    };            