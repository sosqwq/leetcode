#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++){
            auto a = map.find(target - nums[i]);
            // target = nums[i] + a 
            // 找出 a  对应的下标
            //iter->second 是之前存储在 map 中的索引 j，即值为 target - nums[i] 的元素的索引。
            if (a != map.end()){
                //返回对应的下标
                return { a->second ,i};
            }
            map.insert(pair<int, int> (nums[i],i));
        }
        return {};
    }
};