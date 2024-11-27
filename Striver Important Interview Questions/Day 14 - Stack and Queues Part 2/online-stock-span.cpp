
// https://leetcode.com/problems/online-stock-span/description/

#include<bits/stdc++.h>

class StockSpanner {
public:
    stack<int> st;
    // vector<int> output;
    int i;
    bool firstTime;
    vector<int> prices;
    
    StockSpanner() {
        st.push(0);
        // output.push_back(1);
        i = 0;
        firstTime = true;
        
    }
    
    int next(int price) {
        if(firstTime){
            firstTime = false;
            i++;
            prices.push_back(price);
            return 1;
        }
        int ans = -1;
        while(!st.empty() && price >= prices[st.top()]) st.pop();
        if(st.empty()) ans = i+1;
        else ans = i - st.top();
        st.push(i);
        prices.push_back(price);
        i++;
        return ans;
            
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 