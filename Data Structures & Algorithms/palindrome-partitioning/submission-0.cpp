class Solution {
public:
    void solve(int ind,int n,string &s,vector<string>&temp,vector<vector<string>>&ans){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i < n;i++){
            if(isValid(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    bool isValid(int l,int r,string &s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string>temp;
        vector<vector<string>>ans;
        solve(0,n,s,temp,ans);
        return ans;
    }
};