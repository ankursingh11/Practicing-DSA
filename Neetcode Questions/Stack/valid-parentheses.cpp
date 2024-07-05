
// https://leetcode.com/problems/valid-parentheses/

bool checkOpening(char ch){
    if(ch == '[' || ch == '(' || ch == '{') return true;
    return false;
}

class Solution {
public:
    bool isValid(string s) {
        
        if(s.empty()) return true;

        stack<char> st;
        for(auto ch : s){
            if(checkOpening(ch)) st.push(ch);
            else{
                if(st.empty()) return false;
                
                if(st.top() == '[' && ch == ']'){
                    st.pop();
                    continue;
                }
                else if(st.top() == '(' && ch == ')'){
                    st.pop();
                    continue;
                }
                else if(st.top() == '{' && ch == '}'){
                    st.pop();
                    continue;
                }
                else return false;
            }
        }

        if(st.empty()) return true;
        return false;
    }
};