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
    
        bool backtracking(vector<vector<char>> & chessboard){
            for(int i = 0; i< chessboard.size(); i++){
                for( int j = 0; j < chessboard[0].size(); j++){
                    if(chessboard[i][j] == '.'){
                    for( char k = '1'; k<= '9';k++){
                        if(isValid(i,j,k, chessboard)){
                            chessboard[i][j] = k;
                            if(backtracking(chessboard)) return true;
                            chessboard[i][j] = '.';
                        }
                    }
                    return false;
                    }
                }
            }
            return true;
        }
    
        bool isValid(int row, int col , char val, vector<vector<char>> chessboard){
            
            for(int i = 0; i< 9; i++){
                if(chessboard [i][col] == val ){
                    return false;
                }
            }
    
            for(int j = 0; j < 9; j++ ){
                if(chessboard [row][j] == val){
                    return false;
                }
            }
            int startRow = (row/3) * 3;
            int startCol = (col/3) * 3;
    
            for(int i = startRow; i< startRow + 3; i++){
                for( int j = startCol; j < startCol + 3; j++){
                    if(chessboard [i][j] == val){
                        return false;
                    }
                }
            } 
            return true;
        }
            void solveSudoku(vector<vector<char>>& board) {
                backtracking(board);
            }
    };