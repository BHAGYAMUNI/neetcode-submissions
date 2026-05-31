class Solution {
public:
    void solve(vector<int>&nums,int idx,int n,vector<int>&temp,vector<vector<int>>&ans){
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,n,temp,ans);
        temp.pop_back();
        solve(nums,idx+1,n,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,0,n,temp,ans);
        return ans;
    }
};
