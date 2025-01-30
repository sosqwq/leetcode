//这题实际上是用双指针来作的，hash table 会很麻烦

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
        sort(nums.begin(),nums.end());

        for(int i = 0;  i< nums.size();i++){
            if(nums[i]> 0){
                return result;  
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 双指针
            int left = i+1;
            int right = nums.size() -1;

            while(right> left){
                if(nums[i]+ nums[left]+ nums[right] > 0){
                    right --;
                }
                else if(nums[i]+ nums[left]+ nums[right] <0){
                    left ++;
                }
                else {
                    result.push_back(vector <int> {nums[i], nums[left], nums[right]});
                    //去重
                    while( right > left && nums[right] == nums[right -1]){
                        right --;
                    }

                    while(right > left && nums[left] == nums[left +1]){
                        left++;
                    }
                    right --;
                    left ++;

                }
            }
        }
        return result;
    }
};