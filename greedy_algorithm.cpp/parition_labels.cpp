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
        vector<int> partitionLabels(string s) {
            int hash[27] = {0};
            for(int i = 0; i< s.size();i++){
                 // 统计每一个字符最后出现的位置
                hash[s[i] - 'a'] = i;
            }

            int left = 0;
            int right = 0;
            vector<int> result;
            for(int i= 0; i< s.size(); i++){
                right = max(right, hash[s[i]]- 'a');
                if(i == right){
                    result.push_back(right -left +1);
                    left =i +1;
                }
            }
            return result;
        }
    };