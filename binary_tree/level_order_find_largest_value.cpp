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
    TreeNode ():val(0), left(nullptr),right(nullptr){}
};

class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            queue<TreeNode *> que;
            vector<int> result;

            if(root != NULL) que.push(root);


            while(! que.empty()){
                int size = que.size();
                int largest =0;

                while(size--){
                    TreeNode * node = que.front();
                    if(largest < node ->val){
                        largest = node -> val;
                    }
                    if(node -> left) que.push(node-> left);
                    if(node -> right) que.push(node-> right);
                }
                result.push_back(largest);
            }

            return result;
        }
    };