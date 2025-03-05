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
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode():val(0),left(nullptr),right(nullptr){}

};

class Solution {
    public:
        int findBottomLeftValue(TreeNode* root) {
            queue<TreeNode * > queue;
            int result =0;
            

            if(root != NULL) queue.push(root);

            while (!queue.empty()){
                
                int size = queue.size();
            
                for(int i = 0;i< size; i++){
                    TreeNode * node = queue.front();
                    if(i == 0){
                        result = node -> val;
                    }
                    queue.pop();
                    if(node -> left) queue.push(node -> left);
                    if(node -> right) queue.push(node -> right);
                }
            }
            return result;

        }
    };