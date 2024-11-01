
// https://leetcode.com/problems/binary-search/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = (start + end)>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) start++;
            else end--;
        }

        return -1;
    }
};