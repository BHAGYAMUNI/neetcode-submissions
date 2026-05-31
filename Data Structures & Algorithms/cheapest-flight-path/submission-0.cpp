class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjL(n);
        for(auto &it:flights){
            adjL[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}}); // {stops,{node,dis}}
        vector<int>dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adjL[node]){
                int wt = it.second;
                if(dis + wt < dist[it.first]){
                    dist[it.first] = dis + wt;
                    q.push({stops+1,{it.first,dis+wt}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};
