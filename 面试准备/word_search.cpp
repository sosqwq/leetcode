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
    vector<vector<char>> board;
    bool backtracking(vector<vector<char>> & board, string & word, int index, int x, int y){
        if(index == word.size()) {
            return true;
        }

        if(x <0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index]){
            return false;
        }
        char temp = board[x][y];
        board [x][y] = '#';

        bool found = backtracking(board, word, index + 1, x + 1, y)||
        backtracking(board, word, index + 1, x - 1, y) || 
        backtracking(board, word, index + 1, x , y + 1) ||
        backtracking(board, word, index + 1, x, y -1 ) ;

        board [x][y] = temp;
        return found;

    }
        bool exist(vector<vector<char>>& board, string word) {
            int m =  board.size();
            int n = board[0].size();

            for(int i = 0; i< m; i ++){
                for(int j = 0; j < n; j++){
                    if(backtracking (board, word, 0, i, j)){
                        return true;
                    }
                }
            }
            return false;
        }
    };
    