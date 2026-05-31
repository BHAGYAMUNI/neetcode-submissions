class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<unordered_set<char>>row(9),col(9),box(9);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                int boxInd = (i / 3) * 3 + (j / 3);
                if(row[i].count(ch) || col[j].count(ch) || box[boxInd].count(ch)){
                    return false;
                }
                row[i].insert(ch);
                col[j].insert(ch);
                box[boxInd].insert(ch);
            }
        }
        return true;
    }
};
