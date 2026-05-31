class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{
                if(st.empty()) return false;
                char k = st.top();
                st.pop();
                if((k == '[' && ch != ']') || (k == '(' && ch != ')') || (k == '{' && ch != '}')) return false;
            }
        }
        return st.empty();
    }
};
