
// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &nums, int k) {
    
    vector<int> ans;
    int n = nums.size();
    if(n == 0) return ans;
    
    unordered_map<int, int> mp;
    
    int i = 0;
    for( ; i < k; i++) mp[nums[i]]++;
    
    ans.push_back(mp.size());
    
    for( ; i < n; i++){
        if(mp[nums[i-k]] > 1) mp[nums[i-k]]--;
        else mp.erase(nums[i-k]);
        
        mp[nums[i]]++;
        ans.push_back(mp.size());
    }
    
    return ans;
}
