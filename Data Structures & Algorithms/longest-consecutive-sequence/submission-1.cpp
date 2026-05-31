class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_set<int>mp(nums.begin(),nums.end());
        for(int num : mp){
            if(mp.count(num - 1) == 0){
                int start = num;
                int c = 1;
                while(mp.count(start+1) != 0){
                    start++;
                    c++;
                }
                maxi = max(maxi,c);
            }
        }
        return maxi;
    }
};