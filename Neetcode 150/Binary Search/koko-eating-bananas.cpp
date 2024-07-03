
// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:

    bool canEatBananas(vector<int>&piles, int mid, int h){

        float hours = 0;
        for(auto pile : piles){
            hours += (pile + mid - 1) / mid; // This is an integer equivalent of ceil(pile/mid)
        }

        return hours <= h;    
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());
        int minSpeed = 1; // consider minSpeed as low
        int maxSpeed = piles.back(); // consider maxSpeed as high

        while(minSpeed < maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed)/2;
            
            if(canEatBananas(piles, mid, h)) maxSpeed = mid;
            else minSpeed = mid + 1;
        }

        return minSpeed;
    }
};