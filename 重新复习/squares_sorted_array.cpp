#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int k = nums.size()-1;
        vector<int> result(k+1);
        int i = 0;
        int j = nums.size()-1;
        while (i<= j){
            int numi = nums[i] * nums[i];
            int numj = nums[j] *nums[j];
            result[k] = numi > numj  ? (numi,i++ ):(numj, j--);
            k--;
        }
        return result;
    }
};