
// Source: https://leetcode.com/problems/squares-of-a-sorted-array/
//include library
#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size()-1;
        vector<int> answear(nums.size()) ;
        for(int i = 0,j = nums.size() -1; i <= j;){
            int newI = nums[i] * nums[i];
            int newJ= nums[j] * nums[j];
            if ( newI < newJ){
                answear[k] = newJ;
                j--;
                k--;
            }
            else {
                answear[k]= newI;
                i++;
                k--;
            }

        }
        return answear;
    }
};