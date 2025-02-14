#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;



class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;
            if(s.size() %2 != 0){
                return false;
            }
            for(int i= 0; i<s.size();i++){
                if(s[i] == '('){
                    stack.push(')');
                }
                else if (s[i] == '['){
                    stack.push(']');
                }
                else if (s[i] == '{'){
                    stack.push('}');
                }
                else if(stack.empty()&& stack.top() != s[i]){
                    return false;
                }
                else{
                    stack.pop();
                }
            }

            return stack.empty();
        }
    };