#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> isVisit = vector<vector<bool>>(board.size(),
            vector<bool>(board[0].size(), false));
         for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(isExist(board, isVisit, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isExist(vector<vector<char>> &board, vector<vector<bool>> &isVisit,
        int i, int j, int idx, string &word) {
        if(idx == word.size()) {
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if(isVisit[i][j]) {
            return false;
        }
        if(board[i][j] != word[idx]) {
            return false;
        }
        isVisit[i][j] = true;
        if(isExist(board, isVisit, i - 1, j, idx + 1, word) ||
            isExist(board, isVisit, i, j + 1, idx + 1, word) ||
            isExist(board, isVisit, i + 1, j, idx + 1, word) ||
            isExist(board, isVisit, i, j - 1, idx + 1, word)) {
            return true;
        }
        isVisit[i][j] = false;
        return false;
    }
};


int main() {
    Solution s;
    vector<vector<char>> board = {
        //{'A', 'B', 'C', 'E'},
        //{'S', 'F', 'C', 'S'},
        //{'A', 'D', 'E', 'E'}
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    cout << s.exist(board, "ABCEFSADEESE") << endl;
}
