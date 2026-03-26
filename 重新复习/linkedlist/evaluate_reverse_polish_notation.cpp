#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
        int evalRPN(vector<string>& tokens) {
            stack <long long> st;
            for(int i = 0; i< tokens.size(); i++){
                if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                    long long num1 = st.top();
                    st.pop();
                    long long num2 = st.top();
                    st.pop();
                    if(tokens[i] == "+") st.push(num1 + num2);
                    if(tokens[i] == "-") st.push(num1 - num2);
                    if(tokens[i] == "*") st.push(num1 * num2);
                    if(tokens[i] == "/") st.push(num1 / num2);
                }
                else {
                    //stoll 将字符串 str 中的数字 转换为 long long 整数。
                    st.push(stoll(tokens[i]));
                }
            }
            long long result = st.top();
            st.pop();
            return result;
        }
};