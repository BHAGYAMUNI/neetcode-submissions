class Solution {
public:
    void solve(int open,int close,string curr,int n,vector<string>&res){
        if(curr.size() == 2*n){
            res.push_back(curr);
        }
        if(open < n){
            solve(open+1,close,curr+'(',n,res);
        }
        if(close < open){
            solve(open,close+1,curr+')',n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(0,0,"",n,res);
        return res;
    }
};
