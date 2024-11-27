
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        if(n == 0) return ans;

        stack<int> st;
        vector<int> left(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) left[i] = st.top()+1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> right(n, n-1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) right[i] = st.top()-1;
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }

        return ans;
    }
};