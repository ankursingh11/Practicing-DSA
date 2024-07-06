
// https://leetcode.com/problems/detect-squares/

class DetectSquares {

    unordered_map<int, unordered_map<int, int>> points;

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x][y]++;
    }
    
    int count(vector<int> point) {
        
        int px = point[0], py = point[1];

        int ans = 0;
        for(auto xMaps : points){
            for(auto yMaps : xMaps.second){
                int x = xMaps.first;
                int y = yMaps.first;

                // checking for diagonal and skipping points which lie on the same line
                if(px == x|| abs(px-x) != abs(py-y)) continue;
                ans += points[x][y] * points[px][y] * points[x][py];
            }
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */