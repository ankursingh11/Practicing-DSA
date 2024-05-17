

#include<bits/stdc++.h>

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> st;
    for(auto ch : expression){
        if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
        else{
            if(st.empty()) return false;

            char top = st.top();
            st.pop();

            if(top == '(' && ch == ')') continue;
            else if(top == '[' && ch == ']') continue;
            else if(top == '{' && ch == '}') continue;
            else return false;
        }
    }
    if(!st.empty()) return false;
    return true;
}