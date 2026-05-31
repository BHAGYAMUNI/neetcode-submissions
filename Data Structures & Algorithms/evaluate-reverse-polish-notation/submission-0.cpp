class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(string str:tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;
                if(str == "+"){
                    res = a+b;
                }else if(str == "-"){
                    res = a-b;
                }else if(str == "*"){
                    res = a*b;
                }else {
                    res = a/b;
                }
                st.push(res);
            }else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};