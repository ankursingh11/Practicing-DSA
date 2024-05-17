
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxCapacity = 0;
        int n = height.size();
        if(n == 0) return maxCapacity;

        int left = 0, right = n-1;
        while(left < right){
            int currentCapacity = (right - left)*min(height[left], height[right]);
            maxCapacity = max(maxCapacity, currentCapacity);
            height[left] <= height[right] ? left++ : right--;
        }

        return maxCapacity;
    }
};