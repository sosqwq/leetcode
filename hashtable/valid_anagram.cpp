/*
242. Valid Anagram
Easy
Topics
Companies
Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.

 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(int i = 0; i< s.size(); i++){
            arr[s[i]-'a']++;
        }  
        for(int j = 0; j< t.size();j++){
            arr[t[j]-'a']--;
        }
        for (int k = 0; k< 26;k ++){
            if(arr[k] != 0){
                return false;
            }
        }
        return  true;
    }
};