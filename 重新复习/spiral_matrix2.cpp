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

    vector<vector<int>> generateMatrix(int n) {
        // 使用vector定义一个二维数组
        vector<vector<int>> result(n, vector<int> (n,0));
        int startx = 0, starty = 0;
        int offset = 1;
        int j = 0 ,i = 0;
        int count = 1;
        int loop = n / 2; 
        while(loop--){
            j = starty ,i = startx;
            for(i;i< n-offset;i++){
                result[j][i] = count ++;
            }
            for(j; j< n- offset; j++){
                result[j][i] = count ++;
            }

            for(i;i > startx;i--){
                result[j][i] = count ++;
            }
            for(j; j> starty ; j--){
                result[j][i] = count ++;
            }
            starty ++;
            startx ++;
            offset ++;
        }
        if (n % 2) result[n / 2][n / 2] = count;
        return result;
    }
};