
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

class Solution{
	public:
	
	int helper(int mid, int n, int m){
	    long long ans = 1;
	    for(int i = 1; i <= n; i++){
	        ans = ans*mid;
	        if(ans > m) return 2;
	    }
	    if(ans == m) return 0;
	    return 1;
	}
	
	int NthRoot(int n, int m)
	{
	    if(n == 1) return m;
	    
	    int low = 1, high = m;
	    while(low <= high){
	        int mid = (low + high)>>1;
	        int check = helper(mid, n, m);
	        if(check == 0) return mid;
	        else if(check == 2) high = mid-1;
	        else low = mid+1;
	    }
	    return -1;
	}  
};