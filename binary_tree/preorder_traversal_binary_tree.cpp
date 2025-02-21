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
    TreeNode *left;
    TreeNode *right;
    TreeNode (): val(0), left(nullptr), right(nullptr){}
};



class Solution {
    public:
        void Order_traversal(TreeNode * cur, vector<int> & vec){
            if( cur == nullptr){
                return ;
            }
            vec.push_back(cur-> val);
            Order_traversal(cur-> left, vec);
            Order_traversal(cur->right, vec);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            Order_traversal(root, result);
            return result;      
        }
    };