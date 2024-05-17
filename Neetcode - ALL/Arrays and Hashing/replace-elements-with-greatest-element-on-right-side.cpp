
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        vector<int> ans(size, -1);
        if(size == 0) return ans;

        int largestElement = arr[size-1];
        for(int i = size-2; i >= 0; i--){
            ans[i] = largestElement;
            largestElement = max(largestElement, arr[i]);
        }

        return ans;
    }
};