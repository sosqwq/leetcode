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
    TreeNode *left;
    TreeNode *right;

    TreeNode (): val(0),left(nullptr),right(nullptr){}
};
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode * > st;
            vector<int> result;
            if (root == NULL){
                return result;
            }
            st.push(root);
            while(!st.empty()){
                TreeNode * node = st.top();
                st.pop();
                result.push_back(node->val);
                if(node->right) st.push(node->right);
                if(node ->left) st.push(node ->left);

            }
            return result;
        }
};        