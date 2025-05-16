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
        void reverseString(vector<char>& s) {
            int len = s.size();

            for(int i = 0, j= len -1; i < len/2 ; i++, j--){
                swap(s[i],s[j]);
            }
        }
        /*
            void reverseString(vector<char>& s) {
        int len = s.size()-1;
        int i = 0;
        int j = len;

        while (i<j){
            std::swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }*/
    };