
// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:

    int findNextGreaterElement(int num, vector<int>&arr, int startingIndex){
        if(startingIndex == arr.size()) return -1;
        for(int i = startingIndex; i < arr.size(); i++){
            if(arr[i] > num) return arr[i];
        }
        return -1;
    }

    void checkNumInSecondArray(int num, vector<int>&arr, vector<int>&ans, int currentIndex){
        for(int i = 0; i < arr.size(); i++){
            if(num == arr[i]){
                int nextGreater = findNextGreaterElement(num, arr, i+1);
                if(nextGreater != -1){
                    ans[currentIndex] = nextGreater;
                }
            }
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++){
            checkNumInSecondArray(nums1[i], nums2, ans, i);
        }

        return ans;
    }
};