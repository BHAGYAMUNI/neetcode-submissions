class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>& board,int m,int n){
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        vis[r][c] = 1;
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,vis,board,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int j = 0;j < n;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board,m,n);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1,j,vis,board,m,n);
            }
        }
        for(int i = 0;i < m;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,m,n);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,vis,board,m,n);
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
