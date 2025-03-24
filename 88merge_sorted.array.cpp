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
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int n1 = m -1;
            int n2 = n -1;
            int sum = n+m -1;

            while (n1 >= 0 && n2 >= 0){
                if(nums1[n1] > nums2[n2]){
                    nums1[sum] = nums1[n1];
                    n1--;
                }
                else if(nums1[n1] < nums2[n2]){
                    nums1[sum] = nums2[n2];
                    n2--;
                }
                sum --;
            }

            while (n2 > 0){
                nums1[sum] = nums2[n2];
                n2 --;
                sum --;
            }

            // 如果 nums1 还有剩余，其实不需要管，因为本来就在 nums1 里
        }
    };