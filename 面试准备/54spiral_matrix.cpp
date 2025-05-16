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
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            //matrix[0] 列 ，  matrix 行
            if (matrix.empty() || matrix[0].empty()) return {};  // 必加
            int m = matrix.size();
            int n = matrix[0].size();
            int up = 0, down = m - 1;
            int left = 0, right = n - 1;
            vector<int> ans;
            if (matrix.empty() || matrix[0].empty()) return {};
            while(true){
                for(int i = left; i<= right; i++) ans.push_back(matrix[up][i]);
                up ++;
                if(up > down) break;

                for(int i = up; i<= down; i++) ans.push_back(matrix[i][right]);
                right --;
                if(right < left) break;

                for(int i = right; i >= left; i--) ans.push_back(matrix[down][i]);
                down --;
                if(up > down) break;

                for(int i = down; i >= up; i--) ans.push_back(matrix[i][left]);
                left++;
                if(left > right) break;

            }
            return ans;
        }
    };