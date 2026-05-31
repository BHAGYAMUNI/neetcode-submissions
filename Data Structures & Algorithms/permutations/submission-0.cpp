class Solution {
public:
    void solve(int ind,int n,vector<int>& nums,vector<vector<int>>&ans){
        if(ind == n){
            ans.push_back(nums);
        }
        for(int i = ind;i < n;i++){
            swap(nums[i],nums[ind]);
            solve(ind+1,n,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        solve(0,n,nums,ans);
        return ans;
    }
};
