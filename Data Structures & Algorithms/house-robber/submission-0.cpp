class Solution {
public:
    int solve(int n,vector<int>&nums,vector<int>&dp){
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = nums[n] + solve(n-2,nums,dp);
        int notP = 0 + solve(n-1,nums,dp);
        return dp[n] = max(pick,notP);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};
