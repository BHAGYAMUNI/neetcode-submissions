class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string curr = "";
        vector<string>res;
        unordered_map<char,string>mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        solve(0,digits,curr,res,mp);
        return res;
    }
    void solve(int ind,string &digits,string &curr,vector<string>&res,unordered_map<char,string>&mp){
        if(digits.size() == ind){
            res.push_back(curr);
            return;
        }
        for(char c:mp[digits[ind]]){
            curr.push_back(c);
            solve(ind+1,digits,curr,res,mp);
            curr.pop_back();
        }
    }
};
