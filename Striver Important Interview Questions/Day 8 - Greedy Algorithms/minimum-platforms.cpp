
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i = 0, j = 0, ans = 0, platformNeeded = 0;
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        platformNeeded++;
    	        i++;
    	    }else{
    	        platformNeeded--;
    	        j++;
    	    }
    	    
    	    ans = max(ans, platformNeeded);
    	}
    	
    	return ans;
    }
};
