#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;

        for (int i = 0; i< nums.size();i++){
            auto s = map.find(target - nums[i]);
            //iter->second 是之前存储在 map 中的索引 j，即值为 target - nums[i] 的元素的索引。
            if (s != map.end()){
                return {s->second,i};
            }
            map.insert(pair<int, int> (nums[i],i));
        }
        return {};
    }
};