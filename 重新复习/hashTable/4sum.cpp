#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector< vector<int> > result;
            sort(nums.begin(), nums.end());
            
            for(int k = 0; k < nums.size(); k++){
                if(nums[k] > target && nums[k] >= 0) break;
                if( k >0  && nums[k] == nums[k -1]) continue;
                for(int i = k +1; i <nums.size(); i++){
                    if(nums[k] + nums[i] >= 0 &&  nums[k] + nums[i] > target) break;
                    if(i > k +1 && nums[i] == nums[i-1]) continue;

                    int left = i+1;
                    int right = nums.size()-1;

                    while (right > left){
                        long long sum = (long long)nums[k] +nums[i] + nums[right] + nums[left];
                        if(sum > target) right--;
                        else if(sum < target) left++;
                        else {
                            result.push_back(vector<int>  {nums[k],nums[i] ,nums[left],nums[right]});

                            while(right > left && nums[right] == nums[right -1]){
                                right --;
                            }
                            while(right > left && nums[left] == nums[left+1]){
                                left++;
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