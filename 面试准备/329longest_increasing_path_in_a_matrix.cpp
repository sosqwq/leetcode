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
    int m,n;
    vector<vector<int>> memo;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int dfs(vector<vector<int>> & matrix, int x, int y){
            if(memo[x][y] != 0) return memo[x][y];

            int maxLength = 1;//至少为1；
            for(auto & dir : directions){
                int nx = x  + dir[0];
                int ny = y + dir[1];
                // 判断边界，并且必须是严格递增 ,  Snake Sequence ([nx][ny] == [x][y] +1)其他一样；；
                if(nx >= 0 && ny >= 0 && nx < m && ny <n && matrix[nx][ny] > matrix[x][y]){
                    int len = 1 + dfs(matrix, nx, ny);
                    maxLength = max (maxLength, len);

                }
            }
            memo[x][y] = maxLength;
            return maxLength;

        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if(matrix.empty() || matrix[0].empty()) return 0;
            m = matrix.size();
            n = matrix[0].size();
            memo = vector<vector<int>>(m, vector<int>(n, 0));
            int longest;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    longest = max(longest, dfs(matrix, i, j));
                }
            }
            return longest;
        }
    }; 