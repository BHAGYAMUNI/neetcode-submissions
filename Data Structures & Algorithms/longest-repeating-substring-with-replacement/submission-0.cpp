class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0,r = 0;
        unordered_map<char,int>mp;
        int max_freq = 0,maxi = 0;
        while(r < n){
            mp[s[r]]++;
            max_freq = max(max_freq,mp[s[r]]);
            while(r-l+1 - max_freq > k){
                mp[s[l]]--;
                l++;
            } 
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
