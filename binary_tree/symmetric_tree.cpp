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
    bool compare (TreeNode * left, TreeNode * right){
        if (left == NULL && right == NULL) return true;
        else if (left != NULL && right ==NULL) return false;
        else if (left == NULL && right != NULL) return false;

        else if (left -> val != right -> val) return false;

        bool outside = compare( left -> left , right -> right);
        bool inside = compare (left -> right, right -> left);
        bool isSame = outside && inside;

        return isSame;

    }
        bool isSymmetric(TreeNode* root) {
            if(root == NULL) return true;
            return compare(root -> left, root -> right);
        }
    };