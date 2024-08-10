
// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)>>1;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(
                (mid%2 != 0 && nums[mid] == nums[mid-1])
                || (mid%2 == 0 && nums[mid] == nums[mid+1])) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};