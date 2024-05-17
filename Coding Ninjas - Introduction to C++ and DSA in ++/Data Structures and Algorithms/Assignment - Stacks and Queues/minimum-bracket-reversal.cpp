
#include<bits/stdc++.h>

int countBracketReversals(string input) {
	// Write your code here

    int size = input.size();
    if(size%2 != 0) return -1;
    
    stack<char> st;
    for(auto ch : input){
        if(ch == '{') st.push(ch);
        else{
            if(!st.empty() && st.top() == '{') st.pop();
            else st.push(ch);
        }
    }

    int ans = 0;
    while(!st.empty()){
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if(ch1 == ch2) ans +=1;
        else ans +=2;
    }

    return ans;
}