
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int ans = INT_MAX;
        if(nums.size() == 0) return ans;

        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[0] <= nums[mid]) start = mid+1;
            else end = mid;
        }

        return min(nums[0], nums[end]);
    }
};