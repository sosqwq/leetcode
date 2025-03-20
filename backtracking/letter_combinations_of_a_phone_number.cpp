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
    string s;
    vector<string> result;
    string letterMap[10] = {
        "", 
        "", 
        "abc",
        "def", 
        "ghi", 
        "jkl", 
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void backtracking(string digits, int index){
        if(index == digits.size()){
            result.push_back(s);
            return ;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];

        for(int i= 0;i<letter.size();i++){
            s.push_back(letter[i]);
            backtracking(digits,index +1);
            s.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
            s.clear();
            result.clear();
            if (digits.size() == 0) {
                return result;
            }
            backtracking(digits,0);
            return result;
        }
    };