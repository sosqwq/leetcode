#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
    public:
        stack<int> stackIn;
        stack<int> stackOut;

        MyQueue() {
            
        }
        
        void push(int x) {
            stackIn.push(x);
        }
        
        int pop() {
            if(stackOut.empty()){
                while(!stackIn.empty()){
                    stackOut.push(stackIn.top());
                    stackIn.pop();
                }
            }
            int result = stackOut.top();
            stackOut.pop();
            return result;
        }
        
        int peek() {
            if(stackOut.empty()){
                while(!stackIn.empty()){
                    stackOut.push(stackIn.top());
                    stackIn.pop();
                }
            }
            int result = stackOut.top();
            return result;
        }
        
        bool empty() {
            return stackIn.empty()&& stackOut.empty();
        }
    };
    