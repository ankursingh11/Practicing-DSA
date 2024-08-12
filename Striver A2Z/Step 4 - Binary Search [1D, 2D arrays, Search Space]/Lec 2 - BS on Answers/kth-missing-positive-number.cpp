
// https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto ele : arr){
            if(ele <= k) k++;
            else break;
        }
        return k;
    }
};