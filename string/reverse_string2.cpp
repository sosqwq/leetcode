
#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i= 0; i< s.size(); i+= 2*k){
            if(i+k < s.size()){
                reverse(s[i],s[i+k]);
            }
            else{
                reverse(s[i], s[s.size()]);
            }
        }
    }
};