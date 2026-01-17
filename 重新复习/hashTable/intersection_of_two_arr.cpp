#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for(int i = 0; i <nums2.size();i++){
            if(nums_set.find(nums2[i]) != nums_set.end()){
                result_set.insert(nums2[i]);
            }
        }
        return vector<int> (result_set.begin(), result_set.end());
    }
};