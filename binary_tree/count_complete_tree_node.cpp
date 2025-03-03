#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


struct TreeNode {
    int value;
    TreeNode * left;
    TreeNode * right;

    TreeNode():value(0),left(nullptr),right(nullptr){}

};

class Solution {
    public:
    int getNode (TreeNode * cur){
        if(cur == NULL) return 0;
        int leftNode = getNode(cur -> left);
        int rightNode = getNode (cur -> right);
        int result = leftNode + rightNode +1;

        return result;
    }
        int countNodes(TreeNode* root) {
            return getNode(root);
        }
    };