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
    queue<int> que1;
    queue<int> que2;
        MyStack() {
            
        }
        
        void push(int x) {
            que1.push(x);
        }
        
        int pop() {
            
        }
        
        int top() {
            
        }
        
        bool empty() {
            return que1.empty();
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