
// https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        unordered_map<int , int> mp;
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if(st.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        vector<int> nextGreater;
        for(auto num : nums1){
            nextGreater.push_back(mp[num]);
        }

        return nextGreater;
    }
};