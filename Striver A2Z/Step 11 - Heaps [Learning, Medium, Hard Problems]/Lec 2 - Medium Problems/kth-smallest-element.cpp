
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=kth-smallest-element

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto ele : arr) pq.push(ele);
        int ans = -1;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};
