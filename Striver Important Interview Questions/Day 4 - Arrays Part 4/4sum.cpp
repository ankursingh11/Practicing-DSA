
// https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size();
        if(size == 0) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < size-3; i++){
            for(int j = i+1; j < size; j++){
                long long newTarget = (long long)target - nums[i] - nums[j];
                int start = j+1;
                int end = size-1;
                while(start < end){
                    long long currSum = nums[start] + nums[end];
                    
                    if(currSum == newTarget){
                        vector<int> smallAns;
                        smallAns.push_back(nums[i]);
                        smallAns.push_back(nums[j]);
                        smallAns.push_back(nums[start]);
                        smallAns.push_back(nums[end]);
                        ans.push_back(smallAns);

                        // checking for duplicate elements
                        while(start < end && nums[start] == smallAns[2]) start++;
                        while(start < end && nums[end] == smallAns[3]) end--;
                    }else if(currSum < newTarget) start++;
                    else end--;
                }
                // checking for duplicate elements
                while(j+1 < size && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < size && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};