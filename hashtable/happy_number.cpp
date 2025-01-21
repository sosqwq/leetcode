#include <iostream>
#include <vector>
#include <cstring> 
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumNumber(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> happyNumber;
        while(1){
            int sum = sumNumber(n);
            if (sum == 1){
                return true;
            }
             // 如果这个sum曾经出现过，说明已经陷入了无限循环了
            if (happyNumber.find(sum)!= happyNumber.end()){
                return false;
            }
            else{
                happyNumber.insert(sum);
            }

            n= sum;
        }
                
    }
};