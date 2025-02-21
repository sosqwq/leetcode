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
    TreeNode (): val(0),left(nullptr),right(nullptr){

    }
};

class Solution {
    public:
    void inOrder_traversal(TreeNode * cur, vector<int> & vec){
        if(cur == NULL){
            return ;
        }
        inOrder_traversal(cur-> left, vec);
        vec.push_back(cur-> val);
        inOrder_traversal(cur-> right, vec);
    }
        vector<int> inorderTraversal(TreeNode* root) {
            vector <int> result;
            inOrder_traversal(root, result);
            return result;
        }
    };