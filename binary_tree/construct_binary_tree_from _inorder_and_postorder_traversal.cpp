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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
    TreeNode * traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return NULL;

        int rootval = postorder[postorder.size()-1];
        TreeNode * root = new TreeNode(rootval);

        if(postorder.size() == 1) return root;

        int index;// 找到中序遍历的切割点
        for(index = 0; index <inorder.size();index++){
            if(inorder[index] == rootval) break;
        }
        // 左闭右开区间,找中序
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index +1, inorder.end());

        postorder.resize(postorder.size()-1);
        // 左闭右开，注意这里使用了左中序数组大小作为切割点：[0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+ leftInorder.size(), postorder.end());

        root -> left = traversal(leftInorder, leftPostorder);
        root -> right = traversal(rightInorder,rightPostorder);
        return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.size() == 0|| postorder.size()== 0)return NULL;

            return traversal(inorder, postorder);
        }
    };