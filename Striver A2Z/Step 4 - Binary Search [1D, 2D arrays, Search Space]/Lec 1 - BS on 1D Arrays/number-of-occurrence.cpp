
// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

class Solution{
public:	

    int lower_bound(int arr[], int target, int low, int high){
        while(low <= high){
            int mid = (low + high)>>1;
            if(arr[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return low;
    }

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int low = 0, high = n-1;
	    
	    int startingPosition = lower_bound(arr, x, low, high);
	    int endingPosition = lower_bound(arr, x+1, low, high)-1;
	    
	    if(startingPosition < n && arr[startingPosition] == x){
	        return (endingPosition-startingPosition+1);
	    }
	    return 0;
	    
	}
};