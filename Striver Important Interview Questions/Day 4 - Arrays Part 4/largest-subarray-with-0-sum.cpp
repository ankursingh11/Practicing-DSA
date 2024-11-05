
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int maxLength = 0;
        int n = arr.size();
        
        if(n == 0) return maxLength;
        
        for(int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                if(maxLength < i+1) maxLength = i+1;
            }else if(mp.count(arr[i]) > 0){
                if(maxLength < i-mp[arr[i]]) maxLength = i - mp[arr[i]];
            }else mp[arr[i]] = i;
        }
        
        return maxLength;
    }
};