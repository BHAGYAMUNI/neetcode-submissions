class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int c = 0;
        for(auto it:mp){
            if(it.second > 1){
                c++;
            }
        }
        return c>0;
    }
};