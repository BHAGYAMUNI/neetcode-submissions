class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>&vis,int m,int n){
        vis[r][c] = true;
        for(int i = 0;i < 4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr,nc,grid,vis,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,vis,m,n);
                    c++;
                }
            }
        }
        return c;
    }
};
