class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pro1 = nums[0];
        int pro2 = nums[0];
        int res = nums[0];
        for(int i = 1;i < n;i++){
            int temp = max({nums[i],nums[i]*pro1,nums[i]*pro2});
            pro2 = min({nums[i],nums[i]*pro1,nums[i]*pro2});
            pro1 = temp;
            res = max(res,pro1);
        }
        return res;
    }
};
