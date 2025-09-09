class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                st.push(s[i]);
            }
            if(st.empty() == true) return false;
            if(s[i] == ')'){
                if(st.top() != '(') return false;
                else st.pop();
            }
            if(s[i] == '}'){
                if(st.top() != '{') return false;
                else st.pop();
            }
            if(s[i] == ']'){
                if(st.top() != '[') return false;
                else st.pop();
            }
        }
        if(st.empty() == true) return true;
        return false;
    }
};