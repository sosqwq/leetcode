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
void traversal(TreeNode * cur , vector<int> & path, vector<string>& result){
    path.push_back(cur -> val);
    if(cur -> left == NULL && cur -> right == NULL) {
        string Spath;
        for (int i = 0; i<path.size();i++){
            Spath += to_string(path[i]);
            Spath += "->";
        }
        result.push_back(Spath);
        return;
    }
    if(cur -> left){
        traversal(cur -> left, path, result); 
        path.pop_back();
    }
    if(cur -> right){
        traversal(cur -> right,path,result);
        path.pop_back();
    }

}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string>result;
        if(root == NULL) return result;

        traversal(root, path, result);
        return result;
    }
};