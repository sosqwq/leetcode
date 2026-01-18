#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());//已经排序过了，这是最小的数
        
        for(int  i=0 ; i< nums.size(); i++){
            if(nums[i] > 0) return result;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(right  > left){
                int target = nums[i] + nums[left] + nums[right];
                if(target < 0){
                    left ++;
                }//target 过大，就缩小右侧指针， 因为 sort过了， right 最大
                else if(target > 0){
                    right --;
                }
                else {
                    result.push_back(vector<int> {nums[i], nums[left] ,nums[right]});
                     //去重,确保这个组合在其中没有出现
                    while (right > left  && nums[left] == nums[left +1] ) left ++;
                    while (right > left  && nums[right] == nums[right -1] ) right--;
                    left ++;
                    right --;
                }
            }
        }
        return result;
    }
};