#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    //using kmp
    void getNext(int *next ,const string& s ){
        int j = -1;
        next[0] = j;

        for (int  i= 1; i< s.size();i++){
            while(j >= 0&& s[i]!= s[j+1]){
                j = next[j];
            }
            if (s[i]== s[j+1]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()== 0){
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);

    }
};