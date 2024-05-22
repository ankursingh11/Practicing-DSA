
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int size = heights.size();
        int ans = INT_MIN;
        if(size == 0) return ans;

        stack<int> st;
        // finding left smaller elements
        int left[size];
        for(int i = 0; i < size; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }

        // emptying the array
        while(!st.empty()) st.pop();

        // finding right smaller elements
        int right[size];
        for(int i = size-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(st.empty()) right[i] = size-1;
            else right[i] = st.top()-1;
            st.push(i);
        }

        for(int i = 0; i < size; i++){
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }

        return ans;
    }
};