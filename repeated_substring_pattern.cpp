#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s +s ;
        t = t.substr(1,t.size()-2);

        if(t.size() == 0){
            return false;
        }
        else if(t.find(s) != string::npos){
            return true;
        }
        
        return false;

    }
};