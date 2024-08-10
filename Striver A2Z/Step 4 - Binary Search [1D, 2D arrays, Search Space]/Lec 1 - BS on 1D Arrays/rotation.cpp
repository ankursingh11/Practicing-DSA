
// https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans = INT_MAX;
        int low = 0;
        int high = arr.size()-1;
        int index = -1;
        
        while(low <= high){
            int mid = (low + high)>>1;
            
            if(arr[low] <= arr[high]){
                if(arr[low] < ans){
                    ans = arr[low];
                    index = low;
                }
            }
            if(arr[low] <= arr[mid]){
                if(arr[low] < ans){
                    ans = arr[low];
                    index = low;
                }
                low = mid+1;
            }else{
                if(arr[mid] < ans){
                    ans = arr[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        return index;
    }
};