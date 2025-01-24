#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int array[26]= {};
        if (ransomNote.size()> magazine.size()){
            return false;
        }

        for (int i = 0; i< magazine.size();i++){
            array[magazine[i]-'a']++;
        }
        for (int j = 0; j< ransomNote.size();j++){
            array[ransomNote[j]-'a']--;
            if(array[ransomNote[j]-'a']<0){
                return false;
            }
           
        } 
        
        return true;
    }
};