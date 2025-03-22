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
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());

            for(int i = 0;i < nums.size(); i++){
                if(nums[i] > 0) return result; //已经排序过了，这是最小的数

                if( i> 0 && nums[i] == nums[i-1]) continue;

                int left = i +1;
                int right = nums.size() -1;

                while(   right >left){
                    int target = nums[i] + nums[left] + nums[right];
                    if(target > 0){
                        right--;
                    }  //target 过大，就缩小右侧指针， 因为 sort过了， right 最大
                    else if(target < 0) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                         //去重,确保这个组合在其中没有出现
                        while (right > left &&  nums[right] ==nums[right -1] ){
                            right --;
                        }
                        while(right > left &&nums[left]== nums[left + 1]  ){
                            left ++;
                        }
                        right --;
                        left ++;
                    }
                }
            }
            return result;
            
        }
    };