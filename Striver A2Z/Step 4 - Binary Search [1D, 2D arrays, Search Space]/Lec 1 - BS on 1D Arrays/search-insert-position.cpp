
// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int insertIndex = n;
        if(n == 0) return insertIndex;

        int start = 0, end = n-1;
        while(start <= end){
            int mid = (start + end)>>1;
            if(nums[mid] >= target){
                insertIndex = mid;
                end = mid-1;
            }else start = mid+1;
        }
        return (nums[0] >= target) ? 0 : insertIndex;
    }
};