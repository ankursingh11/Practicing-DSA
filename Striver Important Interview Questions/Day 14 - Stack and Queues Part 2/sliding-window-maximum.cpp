
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(k > nums.size()) return ans;

        deque<int> window;
        for(int i = 0; i < k; i++){
            while(!window.empty() && nums[i] >= nums[window.back()]) window.pop_back();
            window.push_back(i);
        }

        ans.push_back(nums[window.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!window.empty() && nums[i] >= nums[window.back()]) window.pop_back();
            while(!window.empty() && window.front() <= i-k) window.pop_front();
            window.push_back(i);
            ans.push_back(nums[window.front()]);
        }

        return ans;
    }
};