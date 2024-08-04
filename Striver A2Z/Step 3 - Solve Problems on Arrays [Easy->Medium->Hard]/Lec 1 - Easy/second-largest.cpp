
// https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest

class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int largest = -1;
        int secondLargest = -1;
        
        for(auto ele : arr){
            if(ele > largest){
                secondLargest = largest;
                largest = ele;
            }else if(ele > secondLargest && ele < largest){
                secondLargest = ele;
            }
        }
        return secondLargest;
    }
};