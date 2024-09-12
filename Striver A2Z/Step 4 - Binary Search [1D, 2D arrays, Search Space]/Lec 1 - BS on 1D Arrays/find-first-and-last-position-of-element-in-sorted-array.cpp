
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:

    int lower_bound(vector<int>&nums, int low, int high, int target){
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int low = 0;
        int high = len-1;

        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target+1)-1;
        if(startingPosition < len && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};