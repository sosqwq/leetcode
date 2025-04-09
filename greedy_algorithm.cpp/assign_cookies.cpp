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
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(s.begin(), s.end());
            sort(g.begin(), g.end());
            int index = s.size()-1;
            int result = 0;
            for(int i = g.size()-1; i>= 0; i--){
                if( index >= 0 && s[index] >= g[i] ){
                    index--;
                    result ++;
                }
            }

            return result;

        }
    };