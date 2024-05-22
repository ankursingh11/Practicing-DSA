
// https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> ans;
        if(temperatures.size() == 0) return ans;
        reverse(temperatures.begin(), temperatures.end());
        stack<int> st;
        ans.push_back(0);
        st.push(0);
        
        for(int i = 1; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
            if(!st.empty()) ans.push_back(i - st.top());
            else ans.push_back(0);
            st.push(i);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};