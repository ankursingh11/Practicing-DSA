
// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:

    bool checkValidPoints(int x, int y, int xLimit, int yLimit){
        return (x >= 0 && x < xLimit && y >= 0 && y < yLimit);
    }

    void dfs(vector<vector<int>>& image, int x, int y, int color, int numRows, int numCols, int currentColor, vector<vector<bool>>&visited){
        image[x][y] = color;
        visited[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(checkValidPoints(newX, newY, numRows, numCols) && image[newX][newY] == currentColor && !visited[newX][newY]){
                dfs(image, newX, newY, color, numRows, numCols, currentColor, visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans;
        int numRows = image.size();
        if(numRows == 0) return ans;
        int numCols = image[0].size();

        int currentColor = image[sr][sc];
        vector<vector<bool>>visited(numRows, vector<bool>(numCols, false));
        dfs(image, sr, sc, color, numRows, numCols, currentColor, visited);
        return image;
    }
};