
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int LCS = 0;
        int size = nums.size();
        if(size == 0) return LCS;

        unordered_map<int, int> indexes;
        unordered_map<int, bool> isVisited;
        for(int i = 0; i < size; i++){
            indexes[nums[i]] = i;
            isVisited[nums[i]] = false;
        }

        for(int i = 0; i < size; i++){
            int currentNum = nums[i];
            int tempNum = currentNum;
            int currentCount = 0;

            // forward traversal
            while(!isVisited[currentNum] && indexes.count(currentNum) > 0){
                isVisited[currentNum] = true;
                currentCount++;
                currentNum++;
            }

            // backward traversal
            currentNum = tempNum-1;
            while(!isVisited[currentNum] && indexes.count(currentNum) > 0){
                isVisited[currentNum] = true;
                currentCount++;
                currentNum--;
            }

            LCS = max(LCS, currentCount);
        }
        
        return LCS;
    }
};