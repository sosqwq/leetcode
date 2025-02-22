#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
};


using namespace std;class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode *> que;
            vector<vector<int>> result;

            if(root != NULL){
                que.push(root);
            }
            while(!que.empty()){
                int size = que.size();
                vector<int> vec;
                while(size--){
                    TreeNode* node;
                    node = que.front();
                    vec.push_back(node->val);
                    que.pop();
                    if(node -> left){
                        que.push(node-> left);
                    }
                    if(node -> right){
                        que.push(node->right);
                    }
                }
                result.push_back(vec);

            }
            return result;
        }
    };