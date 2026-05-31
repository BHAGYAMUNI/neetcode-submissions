class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        if(n == 0) return 0;
        dp[0] = nums[0];
        for(int i = 1;i < n;i++){
            int p = nums[i];
            if(i > 1) p += dp[i-2];
            int notP = dp[i-1];
            dp[i] = max(p,notP);
        }
        return dp[n-1];
    }
};
