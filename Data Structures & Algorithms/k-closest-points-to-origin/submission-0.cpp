class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>maxH;
        for(int i = 0;i < points.size();i++){
            maxH.push({points[i][0]*points[i][0] + points[i][1]*points[i][1] , i});
            while(maxH.size() > k){
                maxH.pop();
            }
        }
        vector<vector<int>>ans;
        while(!maxH.empty()){
            int idx = maxH.top().second;
            ans.push_back(points[idx]);
            maxH.pop();
        }
        return ans;
    }
};
