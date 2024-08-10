
// https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return (n-1);

        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high)>>1;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            // we are in the left half
            else if(nums[mid] > nums[mid-1]) low = mid+1;
            // we are in the right half
            else high = mid-1;
        }
        return -1;
    }
};