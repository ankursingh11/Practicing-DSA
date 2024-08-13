
// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        if(s.size() == 0) return ans;

        unordered_map<char, int> freq;
        for(auto ele : s) freq[ele]++;

        priority_queue<pair<int, char>> pq;
        for(auto it : freq) pq.push({it.second, it.first});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            auto ele = top.second;
            auto count = top.first;
            while(count--) ans += ele;
        }
        return ans;
    }
};