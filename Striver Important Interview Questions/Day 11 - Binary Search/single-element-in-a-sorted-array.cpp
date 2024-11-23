
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int start = 0, end = n-1;

        while(start <= end){
            int mid = (start + end)>>1;

            // single element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            // left space
            else if(((mid%2 == 0) && nums[mid] == nums[mid+1]) || ((mid%2 != 0) && nums[mid] == nums[mid-1])) start = mid+1;
            else end = mid-1;
        }

        return -1;
    }
};