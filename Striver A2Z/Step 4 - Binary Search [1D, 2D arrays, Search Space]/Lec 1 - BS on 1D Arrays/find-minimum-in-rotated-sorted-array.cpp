
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        if(n == 0) return ans;

        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)>>1;
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }

        return ans;
    }
};