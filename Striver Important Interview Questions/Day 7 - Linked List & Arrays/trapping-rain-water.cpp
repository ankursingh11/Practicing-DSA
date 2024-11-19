
// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n == 0) return ans;

        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax) leftMax = height[left];
                else ans = ans + (leftMax - height[left]);
                left++;
            }else{
                if(height[right] >= rightMax) rightMax = height[right];
                else ans = ans + (rightMax - height[right]);
                right--;
            }
        }

        return ans;
    }
};