class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0,r = 0,maxF = 0;
        unordered_map<char,int>mp;
        int maxi = 0;
        while(r < n){
            mp[s[r]]++;
            maxF = max(maxF,mp[s[r]]);
            while(r-l+1 - maxF > k){
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
