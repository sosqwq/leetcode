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

    TreeNode (): val(0),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    int maxDepth(TreeNode * root){
        queue<TreeNode* > que;
        int max_depth = 0;
        if(root != NULL) que.push(root);

        while (! que.empty()){
            int size = que.size();
            max_depth ++;
            while(size--){
                TreeNode * node = que.front();
                que.pop();

                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
        }
        return max_depth;
    }
};