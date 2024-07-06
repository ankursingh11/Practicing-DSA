
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>>&matrix, int n, vector<vector<bool>>&visited, vector<string>&ans, string &path, string curr, int x, int y){
        
        // base case
        if(x == n-1 && y == n-1 && matrix[x][y] == 1){
            path = path + curr;
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        // check condition
        if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || matrix[x][y] == 0) return;
        
        // else proceed forward
        visited[x][y] = true;
        path = path + curr;
        
        solve(matrix, n, visited, ans, path, "D", x+1, y);
        solve(matrix, n, visited, ans, path, "R", x, y+1);
        solve(matrix, n, visited, ans, path, "L", x, y-1);
        solve(matrix, n, visited, ans, path, "U", x-1, y);
        
        visited[x][y] = false;
        path.pop_back();
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> ans;
        string path = "";
        string curr = "";
        
        solve(matrix, n, visited, ans, path, curr, 0, 0);
        
        return ans;
    }
};

    