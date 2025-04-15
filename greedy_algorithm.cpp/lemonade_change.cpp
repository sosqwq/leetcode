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
        bool lemonadeChange(vector<int>& bills) {
            int five, ten = 0;
            for(int bill : bills){
                if(bill == 5){
                    five ++;
                }
                if(bill == 10){
                    if(five > 0){
                        five --;
                        ten ++;
                    }
                    else return false;
                }
                if(bill == 20){
                    if(ten >= 1 && five >= 1){
                        five --;
                        ten --;
                    }
                    else if(five >= 3){
                        five -= 3;
                    }
                    else return false;
                }
            }
            // if is done
            return true;
        }
    };