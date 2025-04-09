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
        int wiggleMaxLength(vector<int>& nums) {
            if(nums.size() <= 1){ return 1;}
            int prediff = 0;
            int currdiff = 0;
            int result = 1;

            for(int i = 0; i<  nums.size()-1; i++){
                currdiff = nums[i+1] -nums[i];
                if(prediff >= 0 && currdiff < 0 || prediff <=0 && currdiff > 0){
                    result ++;
                    prediff = currdiff;
                }

            }
            return result;
        }
    };