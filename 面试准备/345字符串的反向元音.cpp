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
        string reverseVowels(string s) {
            unordered_set<char> vowels = { 'a', 'e', 'i','o', 'u','A', 'E', 'I','O', 'U'};
            int i=0, j = s.size() -1;
            bool left,right;
            while(i < j){
                while( i<j && vowels.find(s[i]) == vowels.end()){ 
                    i++;
                }
                while( i<j && vowels.find(s[j])== vowels.end()){
                    j--;
                }

                if(i< j){
                    swap(s[i] , s[j]);
                    i++;
                    j--;
                }
            }
            return s;
        }
    };