#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int len = s.size()-1;

        int i = 0;
        int j = len;

        while (i<j){
            std::swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }
};