
// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int ansRow = -1;
        int maxCount = 0;
        int numRows = arr.size();
        if(numRows == 0) return ansRow;
        int numCols = arr[0].size();
        
        for(int i = 0; i < numRows; i++){
            int count = 0;
            for(int j = 0; j < numCols; j++){
                if(arr[i][j] == 1) count++;
            }
            if(count > maxCount){
                maxCount = count;
                ansRow = i;
            }
        }
        return ansRow;
    }
};

// another optimised approach
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int ansRow = -1;
        int maxCount = 0;
        int numRows = arr.size();
        if(numRows == 0) return ansRow;
        int numCols = arr[0].size();
        
        for(int i = 0; i < numRows; i++){
            int count = numCols - (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
            if(count > maxCount){
                maxCount = count;
                ansRow = i;
            }
        }
        return ansRow;
    }
};