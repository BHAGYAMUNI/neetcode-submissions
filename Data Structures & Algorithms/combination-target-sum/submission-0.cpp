class Solution {
public:
    void solve(int idx,int n,vector<int>&nums,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx >= n || target < 0) return;
        temp.push_back(nums[idx]);
        solve(idx,n,nums,target-nums[idx],temp,ans);
        temp.pop_back();
        solve(idx+1,n,nums,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,n,nums,target,temp,ans);
        return ans;
    }
};
