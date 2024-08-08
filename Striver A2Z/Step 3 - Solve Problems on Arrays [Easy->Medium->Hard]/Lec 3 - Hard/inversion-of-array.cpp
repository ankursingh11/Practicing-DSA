
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

class Solution {
  public:
  
  long long int merge(long long arr[], int start, int mid, int end){
      int i = start, j = mid;
      int k = 0;
      long long temp[end-start+1];
      long long count = 0;
      while(i < mid && j <= end){
          if(arr[i] <= arr[j]) temp[k++] = arr[i++];
          else{
              count += (mid-i);
              temp[k++] = arr[j++];
          }
      }
      while(i < mid) temp[k++] = arr[i++];
      while(j <= end) temp[k++] = arr[j++];
      
      k = 0;
      for(int i = start; i <= end; i++) arr[i] = temp[k++];
      return count;
  }
  
  
    long long int mergeSort(long long arr[], int start, int end){
        long long count = 0;
        if(start < end){
            int mid = (start + end)/2;
            count += mergeSort(arr, start, mid);
            count += mergeSort(arr, mid+1, end);
            count += merge(arr, start, mid+1, end);
        }
        return count;
    }
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        return mergeSort(arr, 0, n-1);
    }
};