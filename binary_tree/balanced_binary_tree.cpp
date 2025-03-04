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
    int value;
    TreeNode * left;
    TreeNode * right;

    TreeNode():value(0),left(nullptr),right(nullptr){}

};

class Solution {
    public:
        int getHight(TreeNode *  cur){
            if (cur == NULL) return 0;
            int result;
            int leftHight = getHight(cur -> left);
            if (leftHight == -1) return -1;
            int rightHight = getHight(cur -> right);  
            if(rightHight == -1) return -1;

            if(abs(rightHight - leftHight) >1) return -1;
            else { 
                result = 1+ max(leftHight, rightHight);
            }
            return result;
        }
        bool isBalanced(TreeNode* root) {
            if(getHight(root) == -1) return false;
            else return true;
        }
    };