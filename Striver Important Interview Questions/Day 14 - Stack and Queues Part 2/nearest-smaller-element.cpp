
// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &arr) {
    
    reverse(arr.begin(), arr.end());
    stack<int> st;
    vector<int> ans;
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[i] <= st.top()) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        
        st.push(arr[i]);
    }
    
    return ans;
}
