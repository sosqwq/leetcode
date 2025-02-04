#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
void reverse(string& s, int start, int end);
class Solution {
public:
    void reverse(string& s, int start, int end) {
            for (int  i = start, j = end; i<j; i++,j--){
                swap (s[i], s[j]);
            }
        }
    void removeExtraSpeaces(string & s){
        int slow = 0;  
        for (int  i=0; i<s.size(); ++i){
                //遇到非空格就处理，即删除所有空格
            if(s[i] != ' '){
                if (slow != 0) {
                    s[slow ++] = ' ';
                } //手动给单词之间添加空格
            while( i < s.size()&& s[i] != ' '){//补上该单词，遇到空格说明单词结束。 
                    s[slow++ ] = s[i++];
                }

                }
            }
            s.resize(slow);//slow的大小即为去除多余空格后的大小
        }
    string reverseWords(string s) {
        removeExtraSpeaces(s);
        reverse(s, 0, s.size()-1);
        int start = 0; 

        for (int i = 0; i<= s.size(); ++i){
            if(i== s.size()|| s[i] == ' '){
                reverse(s, start, i-1);
                start = i +1;
            }
        }
        return s;

    }
};