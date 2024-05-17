

#include<bits/stdc++.h>

void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here

    stack<int> st;
    st.push(0);
    spans[0] = 1;
    for(int i = 1; i < n; i++){
        while(!st.empty() && prices[i] > prices[st.top()]) st.pop();
        if(st.empty()) spans[i] = i + 1;
        else spans[i] = i - st.top();
        st.push(i);
    }

    return;
}