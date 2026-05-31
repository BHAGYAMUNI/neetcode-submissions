class Solution {
public:
    bool dfs(int i,int j,int idx,string &word,vector<vector<char>>& board){
        if(idx == word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(i,j+1,idx+1,word,board) || dfs(i,j-1,idx+1,word,board) || dfs(i+1,j,idx+1,word,board) || dfs(i-1,j,idx+1,word,board);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == word[0] && dfs(i,j,0,word,board)) return true;
            }
        }
        return false;
    }
};
