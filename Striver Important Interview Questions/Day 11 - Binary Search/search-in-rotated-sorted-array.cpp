
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 0) return -1;

        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high)>>1;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }else low = mid+1;
            }else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }else high = mid-1;
            }
        }

        return -1;
    }
};