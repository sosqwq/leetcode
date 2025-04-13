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
        int candy(vector<int>& ratings) {
            vector<int> candy(ratings.size(), 1);
            
            //left< right
            for(int i= 1; i< ratings.size(); i++){
                if(ratings[i]> ratings[i-1]){
                    candy[i] = candy[i-1] +1;
                }
            }
            // right<left
            for(int i = ratings.size()-2; i>=0; i--){
                if(ratings[i] > ratings [i+1]){
                    candy[i] =max(candy[i+1] +1 , candy[i]);
                }
            }
            int result =0 ;
            for(int i = 0; i < ratings.size();i++){
                result += candy[i];
            }
            return result;
        }
    };