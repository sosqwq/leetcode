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
    vector<string> result;
    void backtraking(string s, int starIndex , int pointsum){
        if(pointsum == 3){
            if(isValid(s, starIndex, s.size() -1 )){
                result.push_back(s);
            }
        } 
        for(int i = starIndex; i< s.size(); i++){
                if(isValid(s, starIndex, i)){
                    s.insert(s.begin() + i +1 , '.');
                    pointsum += 1;
                    backtraking(s, i +2, pointsum);// 插入逗点之后下一个子串的起始位置为i+2
                    pointsum -= 1;
                    s.erase(s.begin()+1+i);
                }
                else break;
            }
    }
    bool isValid(const string & s, int start ,int end){
        if(start > end) return false;

        if( s[start] == '0' && start != end){
            return false;
        }

        int num = 0;

        for(int i = start; i<= end; i++){
            if(s[i] > '9' || s[i] < '0'){// 遇到非数字字符不合法
                return false;
            }
            // 写出完整的数值
            num = num * 10 +(s[i] -'0');
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
            backtraking(s, 0,0);
            return result;
        }
    };