class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l = 0,r = 0;
        int maxi = 0;
        int n = s.length();
        while(r < n){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                maxi = max(maxi,r-l+1);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxi;
    }
};
