#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right  = nums.size()-1;
        int left = 0;
        int middle;
        while (left <= right){
            middle = (left + right) /2;
            if(nums[middle] < target){
                left = middle +1;
            }
            else if( nums[middle] > target){
                right = middle -1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};