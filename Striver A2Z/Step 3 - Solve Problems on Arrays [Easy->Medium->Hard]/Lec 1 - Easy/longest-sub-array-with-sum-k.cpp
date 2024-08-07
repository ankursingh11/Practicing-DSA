
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int K) 
    { 
        // Complete the function
        int currSum = 0;
        int maxLength = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            currSum += nums[i];
            if(currSum == K) maxLength = i+1;
            if(mp.find(currSum) == mp.end()) mp[currSum] = i;
            if(mp.find(currSum-K) != mp.end()){
                maxLength = max(maxLength, i - mp[currSum]);
            }
        }
        return maxLength;
    } 
};