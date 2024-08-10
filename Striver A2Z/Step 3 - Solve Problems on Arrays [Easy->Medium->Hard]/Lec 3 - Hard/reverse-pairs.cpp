
// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:

    int merge(vector<int>&nums, int low, int mid, int high){
        int count = 0;
        int j = mid;
        for(int i = low; i < mid; i++){
            while(j <= high && nums[i] > 2LL*nums[j]) j++;
            count += (j-mid);
        }

        int i = low;
        j = mid;
        vector<int> temp;
        while(i < mid && j <= high){
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while(i < mid) temp.push_back(nums[i++]);
        while(j <= high) temp.push_back(nums[j++]);

        for(int i = low, k = 0; i <= high; i++, k++) nums[i] = temp[k];
        return count;
    }

    int reversePairs_helper(vector<int>&nums, int low, int high){
        int count = 0;
        if(low < high){
            int mid = (low + high)>>1;
            count += reversePairs_helper(nums, low, mid);
            count += reversePairs_helper(nums, mid+1, high);
            count += merge(nums, low, mid+1, high);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return reversePairs_helper(nums, 0, nums.size()-1);
    }
};