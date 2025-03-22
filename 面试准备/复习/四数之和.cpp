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
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector< vector<int> > result;
            sort(nums.begin(), nums.end());
            for(int k= 0; k<nums.size();k++){
                if(nums[k] > target && target > 0 && nums[k] > 0){
                    return result;
                }
                if( k > 0 && nums[k] == nums[k-1]){
                    continue;
                }
                for(int j = k+1; j < nums.size(); j++){
                    if(nums[k] > target && target > 0 && nums[k] > 0){
                        return result;
                    }

                    if(j > k+1 && nums[j] == nums[j-1]){
                        continue;
                    }

                    int left = j+1;
                    int right = nums.size()-1;

                    while(right > left){
                        int sum = nums[k] + nums[j] + nums[left] + nums[right];
                        if(sum > target){
                            right --;
                        }
                        else if(sum < target){
                            left ++;
                        }
                        else{
                            result.push_back(vector<int> {nums[k],nums[j], nums[left], nums[right]});
                            while(left < right && nums[left] == nums[left +1]){
                                left++;
                            }
                            while(left < right && nums[right] == nums[right -1]){
                                right --;
                            }
                            left ++;
                            right --;
                        }
                    }
                }
            }
            return result;
        }
    };