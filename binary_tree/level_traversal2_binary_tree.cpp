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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode*> que;
            if(root == NULL) return result;
            que.push(root);
            while(!que.empty()){
                int size;
                size = que.size();
                vector<int> vec;
                while(size--){
                    TreeNode * node = que.front();
                    vec.push_back(node->val);
                    que.pop();
                    if(node->left)que.push(node->left);
                    if(node->right) que.push(node->right);
                }
                result.push_back(vec);
            }
            reverse(result.begin(),result.end());
            return result;
        }
    };