
// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // base cases
        if(n == 0) return -1;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        // place pointers for search space
        int low = 1, high = n-2;
        
        // binary search
        while(low <= high){
            int mid = low + (high-low)/2;

            // check if mid is the single elment 
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            // check if we are in the left half and if we are eliminate the search space
            if(mid%2 == 0 && nums[mid] == nums[mid+1] || mid%2 != 0 && nums[mid] == nums[mid-1]) low = mid+1;
            
            // else we are in the right half
            // if(mid%2 == 0 && nums[mid] == nums[mid-1] || mid%2 != 0 && nums[mid] == nums[mid+1])
            else high = mid-1; 
        }

        return -1;
    }
};