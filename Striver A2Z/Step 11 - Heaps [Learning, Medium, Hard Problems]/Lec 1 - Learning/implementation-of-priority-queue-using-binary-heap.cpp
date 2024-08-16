
// https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementation-of-priority-queue-using-binary-heap

class Solution {
  public:
    int extractMax() {
        // your code here
        int top = H[0];
        swap(H[0],H[s--]);
        shiftDown(0);
        return top;
        
    }
};