#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node* next;
    Node ():val(0), left(nullptr),right(nullptr), next(NULL){}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
        Node* connect(Node* root) {
            queue<Node*> que;
            if(root!= NULL) que.push(root);

            while(!que.empty()){
                int size = que.size();
                Node* node;
                Node* nodepre;
                for(int i = 0;i< size;i++){
                    if( i==0){
                        nodepre = que.front();
                        que.pop();
                        node = nodepre;
                    }
                    else {
                        node = que.front();
                        que.pop();
                        nodepre ->next = node;
                        nodepre = nodepre -> next;
                    }
                    if(node-> left) que.push(node-> left);
                    if(node -> right) que.push(node -> right);
                }
                node-> next = NULL;
            }
            return root;
        }
    };