#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyStack {
    public:
    queue<int> que;
        MyStack() {
            
        }
        
        void push(int x) {
            que.push(x);
        }
        
        int pop() {
            int size = que.size()-1;
            while(size != 1){
                que.push(que.front());
                que.pop();
                size--;
            }
            int result = que.front();
            que.pop();
            return result;
        }
        
        int top() {
            return que.back();
        }
        
        bool empty() {
            return que.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */