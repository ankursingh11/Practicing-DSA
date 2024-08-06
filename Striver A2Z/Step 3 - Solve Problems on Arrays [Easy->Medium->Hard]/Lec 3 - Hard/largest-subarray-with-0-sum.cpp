
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int ansLength = 0;
        if(n == 0) return ansLength;
        
        for(int i = 1; i< n; i++){
            arr[i] += arr[i-1];
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                if(ansLength < i+1) ansLength = i+1;
            }else if(mp.count(arr[i]) > 0){
                if(ansLength < i-mp[arr[i]]) ansLength = i-mp[arr[i]];
            }else mp[arr[i]] = i;
        }
        return ansLength;
    }
};