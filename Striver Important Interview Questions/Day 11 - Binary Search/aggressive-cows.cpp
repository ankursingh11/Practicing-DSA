
// https://www.geeksforgeeks.org/problems/aggressive-cows/0

class Solution {
public:

    bool canPlaceCows(int n, int k, vector<int>&stalls, int dist){
        
        int countCows = 1;
        int lastPosition = stalls[0];
        
        for(int i = 1; i < n; i++){
            if(stalls[i] - lastPosition >= dist){
                lastPosition = stalls[i];
                countCows++;
                if(countCows >= k) return true;
            }
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(canPlaceCows(n, k, stalls, mid)) low = mid+1;
            else high = mid-1;
        }
        
        return high;
    }
};
