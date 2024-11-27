
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        if(k > n || k == 0) return ans;
        if(k == n){
            int maxEle = *max_element(nums.begin(), nums.end());
            ans.push_back(maxEle);
            return ans;
        }

        deque<int> window;
        
        // checking for the first k elements
        for(int i = 0; i < k; i++){
            while(!window.empty() && nums[i] >= nums[window.back()]) window.pop_back();
            window.push_back(i);
        }

        ans.push_back(nums[window.front()]);

        // checking for the rest of the elements
        for(int i = k; i < n; i++){
            while(!window.empty() && nums[i] >= nums[window.back()]) window.pop_back();
            while(!window.empty() && window.front() <= i-k) window.pop_front();
            window.push_back(i);
            ans.push_back(nums[window.front()]);
        }

        return ans;
    }
};