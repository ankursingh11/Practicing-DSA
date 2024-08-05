
// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {

        int left = 0, right = N-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(arr[mid] == K) return 1;
            if(arr[mid] > K) right = mid-1;
            else left = mid + 1;
        }
        return -1;
    }
};