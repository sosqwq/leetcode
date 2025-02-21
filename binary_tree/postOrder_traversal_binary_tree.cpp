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
   TreeNode * left;
   TreeNode * right;
   TreeNode (): val(0), left(nullptr), right(nullptr){}

};

class Solution {
    public:
    void postOrder_traversal(TreeNode * cur, vector<int> vec){
        if(cur == nullptr){
            return ;
        }
        postOrder_traversal(cur -> left, vec);
        postOrder_traversal(cur-> right, vec);
        vec.push_back(cur-> val);

    }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            postOrder_traversal(root, result);
            return result;
            
        }
    };