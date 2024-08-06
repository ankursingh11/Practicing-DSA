
// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++){
            int start = i+1, end = n-1;
            while(start < end){
                int currSum = nums[i] + nums[start] + nums[end];
                if(currSum == 0){
                    vector<int> smallAns{nums[i], nums[start], nums[end]};
                    ans.push_back(smallAns);
                    while(start < end && smallAns[1] == nums[start]) start++;
                    while(start < end && smallAns[2] == nums[end]) end--;
                }
                else if(currSum < 0) start++;
                else end--;
            }
            while(i < n-2 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};