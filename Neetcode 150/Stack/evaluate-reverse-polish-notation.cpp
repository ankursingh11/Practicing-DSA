
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        if(tokens.size() == 0) return stoi(tokens[0]);

        unordered_set<string> operands({"+", "-", "*", "/"});
        for(int i = 0; i < tokens.size(); i++){
            if(operands.find(tokens[i]) != operands.end()){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = 0;
                if(tokens[i] == "+") res = a + b;
                else if(tokens[i] == "-") res = b-a;
                else if(tokens[i] == "*") res = a*b;
                else res = b/a;
                st.push(res);
            }else st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};