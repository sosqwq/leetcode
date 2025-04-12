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
    static bool cmp (int a, int b){
        return abs(a) > abs(b);
    }
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end(), cmp);
            for(int i =0; i< nums.size(); i++){
                if(nums[i]<0 && k>0){
                    k--;
                    nums[i] *= -1;
                }
            }
            if(k%2 ==1) nums[nums.size()-1] *= -1;
            int result =0 ;
            for(int num :nums) result += num;
            return result;
        }
    };