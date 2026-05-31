class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>>maxH;
        for(auto it : mp){
            maxH.push({it.second,it.first});
        }
        vector<int>ans;
        while(k > 0){
            int n = maxH.top().second;
            maxH.pop();
            ans.push_back(n);
            k--;
        }
        return ans;
    }
};
