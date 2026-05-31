class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cntF = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntF++;
            }
        }
        int cnt = 0;
        int time = 0;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i = 0;i < 4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]){
                    cnt++;
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        if(cnt!=cntF) return -1;
        return time;
    }
};
