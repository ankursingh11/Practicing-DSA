
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0) return ans;

        vector<int> positives, negatives;
        for(auto ele : nums){
            if(ele > 0) positives.push_back(ele);
            else negatives.push_back(ele);
        }
        int i = 0; // for positives
        int j = 0; // for negatives
        while(i < positives.size() && j < negatives.size()){
            ans.push_back(positives[i++]);
            ans.push_back(negatives[j++]);
        }
        return ans;
    }
};