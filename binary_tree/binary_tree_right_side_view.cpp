#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode():val(0),left(nullptr),right(nullptr){}

};

class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            queue<TreeNode*> que;
            vector<int> result;

            if(root!= NULL) que.push(root);
            while(!que.empty()){
                int size;
                size = que.size();
                vector<int> vec;
                while(size--){
                    TreeNode* node = que.front();
                    que.pop();
                    vec.push_back(node->val);

                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node-> right);
                }
                result.push_back(vec.back());
            }
            return result;
        }
    };