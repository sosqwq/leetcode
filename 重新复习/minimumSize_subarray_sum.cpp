#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int i =0;
        int sum = 0;
        int subl = 0;
        for(int j= 0; j< nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subl = j-i +1;
                result = min(result , subl);
                sum -= nums[i];
                i++;
            }
        }
        return result==INT_MAX?0:result;
    }
};
