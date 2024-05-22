
// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, p1 = 1, p2 = 1, size = nums.size();

        for(int i = 0; i < size; i++){
            int j = size-i-1;
            p1 = nums[i]*p1;
            p2 = nums[j]*p2;
            ans = max({ans, p1, p2});
            if(p1 == 0) p1 = 1;
            if(p2 == 0) p2 = 1;
        }

        return ans;
    }
};