class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adjL){
        vis[node] = true;
        for(auto it:adjL[node]){
            if(!vis[it]){
                dfs(it,vis,adjL);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adjL(n);
        for(auto edge:edges){
            adjL[edge[0]].push_back(edge[1]);
            adjL[edge[1]].push_back(edge[0]);
        }
        int c = 0;
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                dfs(i,vis,adjL);
                c++;
            }
        }
        return c;
    }
};
