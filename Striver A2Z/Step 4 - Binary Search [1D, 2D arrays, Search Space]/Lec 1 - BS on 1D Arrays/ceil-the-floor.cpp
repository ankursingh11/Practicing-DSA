
// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int maxEle = INT_MAX;
        int minEle = INT_MIN;
        for(auto ele : arr){
            if(ele >= x && ele < maxEle) maxEle = ele;
            if(ele <= x && ele > minEle) minEle = ele;
        }
        maxEle = (maxEle == INT_MAX) ? -1 : maxEle;
        minEle = (minEle == INT_MIN) ? -1 : minEle;
        vector<int> ans{minEle, maxEle};
        return ans;
    }
};