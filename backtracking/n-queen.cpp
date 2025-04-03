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
        vector<vector<string>> result;
        vector<string> chessboard;
        bool isValid(int row, int col, vector<string> & chessboard){
            for(int i=0; i< row; i++){
                if(chessboard [i][col] == 'Q'){
                    return false;
                }
            }

            for(int i= row -1,  j = col -1; i >= 0 && j >= 0; i--,j--){
                if(chessboard[i][j] == 'Q'){
                    return false;
                }
            }

            for(int i= row -1 , j = col +1; i >= 0 && j >= 0; i--,j++){
                if(chessboard [i][j] == 'Q'){
                    return false;
                }
            }
            return true;
        }

        void backtracking(int n, int row, vector<string>& chessboard){
            if(row == n){
                result.push_back(chessboard);
            }

            for(int col = 0; col < n; col++){
                if(isValid(row,col,chessboard)){
                    chessboard[row][col] = 'Q';
                    backtracking(n,row +1, chessboard);
                    chessboard[row][col] = '.';
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> chessboard(n, string(n,'.'));
            backtracking(n,0,chessboard);
            return result;
        }
    };