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
};

class Solution {
    public:

        bool path(TreeNode * node , int target){
            if(node -> left == NULL && node -> right == NULL && target == 0) return true;
            if(node -> left == NULL && node -> right == NULL ) return false;

            if(node -> left){
                target -= node -> left -> val;
                if(path(node-> left, target)) return true;
                target += node -> left->val;
            }
            if( node ->right){
                target -= node -> right -> val;
                if(path(node-> right, target)) return true;
                target += node -> right -> val;
            }
            return false;
            
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == NULL) return false;
            return path(root, targetSum - root->val);
        }
    };