
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < arr.size()-1; i++){
            currSum = arr[i] + arr[i+1];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};