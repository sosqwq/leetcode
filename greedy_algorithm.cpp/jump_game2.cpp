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
        int jump(vector<int>& nums) {
            int cover = nums[0];
            if(nums.size() == 1) return 0;
            int step = 0;
            int next = 0;

            for(int i = 0; i< nums.size(); i++){
                next = max(i+nums[i], next);

                if(i == cover){
                    step ++;
                    cover = next;
                    if(next >= nums.size() -1) break;
                }
            }
            return step;
        }


    };