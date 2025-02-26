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
        TreeNode* invertTree(TreeNode* root) {
            if(root == NULL) return root  ;

            swap(root-> left, root-> right);
            invertTree (root ->left);
            invertTree(root -> right);
            return root;
        }
       
    };