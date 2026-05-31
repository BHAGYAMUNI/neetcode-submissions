class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>>adjL(v);
        for(auto &edge:edges){
            int a = edge[1];
            int b = edge[0];
            adjL[a].push_back(b);
        }
        vector<int>inDeg(v,0);
        for(int i = 0;i < v;i++){
            for(auto it:adjL[i]){
                inDeg[it]++;
            }
        }
        queue<int>q;
        for(int i = 0;i < v;i++){
            if(inDeg[i] == 0) q.push(i);
        }
        int c = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++;
            for(auto it:adjL[node]){
                inDeg[it]--;
                if(inDeg[it] == 0) q.push(it);
            }  
        }
        return v == c;
    }
};
