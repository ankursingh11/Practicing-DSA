
// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        
        stack<int> s;
        
        vector<int> left(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[i] <= arr[s.top()]) s.pop();
            if(s.empty()) left[i] = -1;
            else left[i] = s.top();
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        vector<int> right(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[i] <= arr[s.top()]) s.pop();
            if(s.empty()) right[i] = n;
            else right[i] = s.top();
            s.push(i);
        }
        
        vector<int> ans(n+1);
        for(int i = 0; i < n; i++){
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        
        for(int i = n-1; i >= 1; i--) ans[i] = max(ans[i], ans[i+1]);
        
        ans.erase(ans.begin());
        return ans;
    }
};