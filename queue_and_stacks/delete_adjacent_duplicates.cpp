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
    string removeDuplicates(string s) {
        string result;

        for(char sz  :s){
            if(result.empty() || result.back() != sz){
                result.push_back(sz);
            }
            else if (result.back() == sz){
                result.pop_back();
            }
        }
        return result;
    }
};