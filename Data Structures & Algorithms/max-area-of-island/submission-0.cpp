class Solution {
public:
    int dr[4] = {-1, 0, 1, 0}; // up, right, down, left
    int dc[4] = {0, 1, 0, -1};
    int dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid, int m, int n) {
        vis[r][c] = true;
        int area = 1;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !vis[nr][nc] && grid[nr][nc] == 1) {
                area += dfs(nr, nc, vis, grid, m, n);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;
        int area = 0,maxi = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area = dfs(i, j, vis, grid, m, n);
                    maxi = max(maxi,area);
                }
            }
        }
        return maxi;
    }
};
