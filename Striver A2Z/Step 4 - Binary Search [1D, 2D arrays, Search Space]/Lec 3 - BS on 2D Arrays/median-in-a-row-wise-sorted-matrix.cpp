
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i = 0; i < R; i++){
            if(matrix[i][0] < low) low = matrix[i][0];
            if(matrix[i][C-1] > high) high = matrix[i][C-1];
        }
        
        int desired = (R*C+1)/2;
        while(low < high){
            int mid = (low + high)>>1;
            int place = 0;
            for(int i = 0; i < R; i++){
                place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(place < desired) low = mid+1;
            else high = mid;
        }
        return low;
    }
};