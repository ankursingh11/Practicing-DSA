
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        int n = mat.size();
        
        // putting all the persons in the stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        // checking for the potential celebrity
        while(st.size() != 1){
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            
            if(mat[i][j] == 1) st.push(j);
            else st.push(i);
        }
        
        int potentialCandidate = st.top();
        st.pop();
        
        for(int j = 0; j < n; j++){
            if(j != potentialCandidate){
                if(mat[potentialCandidate][j] == 1 || mat[j][potentialCandidate] == 0) return -1;
            }
        }
        
        return potentialCandidate;
    }
};