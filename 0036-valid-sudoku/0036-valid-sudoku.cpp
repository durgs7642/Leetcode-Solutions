class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        bool res = true;
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];
        for(int i=0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                char digit = board[i][j];
                int index = (i/3)*3 + (j/3);
                if(row[i].count(digit) || col[j].count(digit) || box[index].count(digit))             return false; 

                row[i].insert(digit);
                col[j].insert(digit);
                box[index].insert(digit);
            }
        }
        return true;
    }
};