class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char ch : s){
            if(isalnum(ch)) ans += tolower(ch);
            else continue;
        }
        int n = ans.length();
        int l = 0,r = n-1;
        while(l < r){
            if(ans[l]!=ans[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
