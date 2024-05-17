
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int maxLength = 0;
        int size = arr.size();
        if(size == 0) return maxLength;
        
        for(int i = 1; i < size; i++) arr[i] = arr[i] + arr[i-1];
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                if(maxLength < i+1) maxLength = i +1;
            }
            else if(mp.count(arr[i]) > 0){
                if(maxLength < i - mp[arr[i]]) maxLength = i - mp[arr[i]];
            }
            else mp[arr[i]] = i;
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends