#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            //找最大
            //分割数组
            // 如果在左边就是左
            // 递归
            TreeNode * root = new TreeNode(0);
            if(nums.size() == 0) return root;

            if(nums.size() == 1){
                root -> val = nums[0];
                return root;
            }

            int maxval =0;
            int maxindex = 0;
            for(int index = 0;index< nums.size();index++){
        
                if(maxval< nums[index]){
                    maxval = nums[index];
                    maxindex = index;
                }
            }
            root -> val = maxval;
            
            if(maxindex > 0){
                vector<int> leftNums(nums.begin(),nums.begin()+ maxindex);
                root -> left = constructMaximumBinaryTree(leftNums);
            }
            if(maxindex < nums.size()-1){
                vector<int> rightNums(nums.begin() + maxindex + 1, nums.end());
                root -> right = constructMaximumBinaryTree(rightNums);
            }
            return root;

        }
    };