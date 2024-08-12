
// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:

    bool canFinish(vector<int>&piles, int h, int eatingSpeed){
        int time = 0;
        for(auto pile : piles){
            time += ceil((double)pile/eatingSpeed);
        }
        return (time <= h) ? true : false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = (low + high)>>1;
            if(canFinish(piles, h, mid)) high = mid;
            else low = mid+1;
        }

        return low;
    }
};