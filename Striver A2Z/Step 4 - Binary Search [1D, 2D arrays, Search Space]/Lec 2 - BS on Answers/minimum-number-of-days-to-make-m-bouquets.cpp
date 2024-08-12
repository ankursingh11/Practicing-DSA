
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:

    bool check(vector<int>&bloomDay, int m, int k, int day){
        int count = 0;
        int noB = 0;
        for(auto ele : bloomDay){
            if(ele <= day) count++;
            else{
                noB += (count/k);
                count = 0;
            }
        }
        noB += (count/k);
        return noB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = (low + high)>>1;
            if(check(bloomDay, m, k, mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};