
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:

    int sumByD(vector<int>&nums, int div){
        int sum = 0;
        for(auto ele : nums){
            sum += ceil((double)ele/div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
     int n = nums.size();
     if(n > threshold) return -1;

     int low = 1;
     int high = *max_element(nums.begin(), nums.end());
     while(low <= high){
        int mid = (low + high)>>1;
        if(sumByD(nums, mid) <= threshold) high = mid-1;
        else low = mid+1;
     }
     return low;   
    }
};