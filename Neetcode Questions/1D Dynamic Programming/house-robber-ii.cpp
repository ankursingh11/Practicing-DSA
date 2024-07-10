
// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:

    int solve(vector<int>&nums){
        int n = nums.size();
        
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            nums[i] = max(nums[i-1], nums[i] + nums[i-2]);
        }

        return nums[n-1];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return max(0, nums[0]);
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> skipFirstHouse(n-1), skipLastHouse(n-1);

        for(int i = 0; i < n-1; i++){
            skipLastHouse[i] = nums[i];
            skipFirstHouse[i] = nums[i+1];
        }

        int ans1 = solve(skipFirstHouse);
        int ans2 = solve(skipLastHouse);

        return max(ans1, ans2);
    }
};