class Solution {
public:
    void solve(int ind,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i = ind;i < n;i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,n,nums,temp,ans);
        return ans;
    }
};
