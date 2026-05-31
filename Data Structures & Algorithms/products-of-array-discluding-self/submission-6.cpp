class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int c = 0,pro = 1;
        for(int num : nums){
            if(num == 0) c++;
            else pro *= num;
        }
        vector<int>res(n);
        if(c > 1){
            return vector<int>(n,0);
        }
        for(int i = 0;i < n;i++){
            if(c > 0){
                res[i] = (nums[i] == 0) ? pro : 0;
            }else{
                res[i] = pro/nums[i];
            }
        }
        return res;
    }
};
