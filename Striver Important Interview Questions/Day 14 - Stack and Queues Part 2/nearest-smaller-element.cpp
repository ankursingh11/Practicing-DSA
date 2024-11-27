
// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &arr) {
    
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] <= st.top()) st.pop();
        
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        
        st.push(arr[i]);
    }
    
    return ans;
}
