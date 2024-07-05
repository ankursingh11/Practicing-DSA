
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:

    int foundTarget(vector<int>&nums, int start, int end, int target){
        if(start > end) return -1;

        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        int leftAns = foundTarget(nums, start, mid-1, target);
        if(leftAns != -1) return leftAns;
        int rightAns = foundTarget(nums, mid+1, end, target);
        if(rightAns != -1) return rightAns;

        return -1;
    }

    int search(vector<int>& nums, int target) {
        return foundTarget(nums, 0, nums.size()-1, target);
    }
};