
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        int n = nums.size();
        if(n == 0) return maxLength;

        unordered_map<int, int> index;
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++){
            index[nums[i]] = i;
            visited[nums[i]] = false;
        }

        for(int i = 0; i < n; i++){
            int tempNum = nums[i];
            int tempNumCopy = tempNum;
            int currLength = 0;
            // forward
            while(index.count(tempNum) > 0 && !visited[tempNum]){
                visited[tempNum] = true;
                currLength++;
                tempNum++;
            }
            // backward
            tempNum = tempNumCopy-1;
            while(index.count(tempNum) > 0 && !visited[tempNum]){
                visited[tempNum] = true;
                currLength++;
                tempNum--;
            }
            maxLength = max(maxLength, currLength);
        }

        return maxLength;
    }
};