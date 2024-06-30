
// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        int targetSum = sum/2;
        
        vector<vector<bool>> dp(size+1, vector<bool>(targetSum+1, false));
        for(int i = 0; i <= size; i++){
            for(int j = 0; j <= targetSum; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }

        for(int i = 1; i <= size; i++){
            for(int j = 1; j <= targetSum; j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[size][targetSum];
    }
};