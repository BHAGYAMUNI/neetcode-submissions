class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = 0;
        for(int i = 0;i < n;i++){
            int start = nums[i];
            int len = 1;
            if(mp.find(start-1) == mp.end()){
                while(mp.find(start+1)!=mp.end()){
                    start++;
                    len++;
                }
            }
            maxi = max(maxi,len);
        }
        return maxi;
    }
};
