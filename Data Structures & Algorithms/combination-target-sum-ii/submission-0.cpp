class Solution {
public:
    void solve(int idx,int n,int target,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i < n;i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            solve(i+1,n,target-nums[i],nums,temp,ans);  
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,n,target,nums,temp,ans);
        return ans;
    }
};
