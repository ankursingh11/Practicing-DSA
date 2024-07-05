
// https://leetcode.com/problems/car-fleet/description/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int size = position.size();
        vector<pair<int, double>> cars;
        for(int i = 0; i < size; i++){
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int fleet = 0;
        for(int i = size-1; i >= 0; i--){
            double currTime = cars[i].second;
            if(currTime > maxTime){
                maxTime = currTime;
                fleet++;
            }
        }

        return fleet;
    }
};