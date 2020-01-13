#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            set<char> capacity;
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    continue;
                }
                if(capacity.find(board[i][j]) != capacity.end()) {
                    return false;
                }
                capacity.insert(board[i][j]);
            }
        }
        for(int i = 0; i < 9; ++i) {
            set<char> capacity;
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') {
                    continue;
                }
                if(capacity.find(board[j][i]) != capacity.end()) {
                    return false;
                }
                capacity.insert(board[j][i]);
            }
        }
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                set<char> capacity;
                for(int m = i * 3; m < i * 3 + 3; ++m) {
                    for(int n = j * 3; n < j * 3 + 3; ++n) {
                        if(board[m][n] == '.') {
                            continue;
                        }
                        if(capacity.find(board[m][n]) != capacity.end()) {
                            return false;
                        }
                        capacity.insert(board[m][n]);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution s;
    cout << s.isValidSudoku(board) << endl;
}
