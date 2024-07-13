
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix

class Solution{   
public:
    
    int findUpper(vector<int>&arr, int n, int element){
        int low = 0, high = n-1;
        
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] > element){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }

    int findSmallEqual(vector<vector<int>>&matrix, int numRows, int numCols, int mid){
        
        int smallEqual = 0;
        for(int i = 0; i < numRows; i++){
            smallEqual += findUpper(matrix[i], numCols, mid);
        }
        return smallEqual;
    }

    int median(vector<vector<int>> &matrix, int numRows, int numCols){
        
        // finding the search space
        int minElement = INT_MAX, maxElement = INT_MIN;
        for(int i = 0; i < numRows; i++){
            minElement = min(minElement, matrix[i][0]);
            maxElement = max(maxElement, matrix[i][numCols-1]);
        }
        
        int low = minElement, high = maxElement;
        
        int req = numRows*numCols/2;;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            // finding the number of elements smaller than equal to mid
            int smallEqual = findSmallEqual(matrix, numRows, numCols, mid);
            if(smallEqual <= req) low = mid + 1;
            else high = mid-1;
        }
        
        return low;
        
    }
};


