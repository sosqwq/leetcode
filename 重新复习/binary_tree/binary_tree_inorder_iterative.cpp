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
    TreeNode(): val(0), left(nullptr), right(nullptr){}
};

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode * cur = root;
        while( cur != NULL|| !st.empty()){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                result.push_back(cur-> val);
                cur = cur->right;
                st.pop();
            }

        }
        return result;
    }
};