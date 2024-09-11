
// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

class Solution {
  public:
    int largest(vector<int> &arr) {
        int ans = *max_element(arr.begin(), arr.end());
        return ans;
    }
};
