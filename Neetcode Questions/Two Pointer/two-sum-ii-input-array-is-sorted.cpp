
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        int size = numbers.size();
        if(size == 0) return ans;

        int left = 0, right = size-1;
        while(left < right){
            int currSum = numbers[left] + numbers[right];
            if(currSum == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }else if(currSum > target) right--;
            else left++;
        }

        return ans;
    }
};