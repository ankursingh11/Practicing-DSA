
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:

    int findRotations(vector<int>&nums, int n){
        int x = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]) return x;
            x++;
        }
        return x;
    }


    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return true;

        // find x -> rotated by how many position
        int x = findRotations(nums, n);
        
        // find whether array is sorted or not;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; i++){
            if(sorted[i] != nums[(i+x)%n]) return false;
        }
        return true;
    }
};