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
    string removeDuplicates(string s) {
        string result;

        for(char sz  :s){
            if(result.empty() || sz != result.back() ){
                result.push_back(sz);
            }
            else if ( sz == result.back()){
                result.pop_back();
            }
        }
        return result;
    }
};