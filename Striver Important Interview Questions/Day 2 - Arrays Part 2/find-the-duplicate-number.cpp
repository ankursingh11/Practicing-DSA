
// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        slow = nums[slow];
        int fast = nums[0];
        fast = nums[nums[fast]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};