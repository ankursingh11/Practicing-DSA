
// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else{
                if(st.empty()) return false;
                else if(ch == ']' && st.top() == '['){
                    st.pop();
                    continue;
                }
                else if(ch == '}' && st.top() == '{'){
                    st.pop();
                    continue;
                }
                else if(ch == ')' && st.top() == '('){
                    st.pop();
                    continue;
                }else return false;
            }
        }

        if(st.empty()) return true;
        return false;
    }
};