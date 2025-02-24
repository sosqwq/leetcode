#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(NULL),right(NULL), next(NULL){}
};

class Solution {
    public:
        Node* connect(Node* root) {
            queue<Node* > que;
            vector<int> vec;

            if(root != NULL) que.push(root);

            while(! que.empty()){
                int size = que.size();
                Node * nodepre;
                Node* node;
                for(int i=0;i<size;i++) {
                    if(i== 0){
                        nodepre = que.front();
                        que.pop();
                        node = nodepre;
                    }
                    else{
                        node = que.front();
                        nodepre ->next = node;
                        nodepre = nodepre ->next;
                        que.pop();
  
                    }                      
                    if(node->left) que.push(node ->left);
                        
                    if(node -> right) que.push(node -> right);
                }
                node -> next = NULL;
                
            }

            return root;
        }
    };