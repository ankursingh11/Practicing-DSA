
// https://leetcode.com/problems/merge-intervals/

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    let ans = [];
    let n = intervals.length;
    if(n === 0) return ans;

    intervals = intervals.sort((a, b) => a[0] - b[0]);

    let currInterval = intervals[0];
    for(let i = 1; i < n; i++){
        if(currInterval[1] >= intervals[i][0]){
            currInterval[0] = Math.min(currInterval[0], intervals[i][0]);
            currInterval[1] = Math.max(currInterval[1], intervals[i][1]);
        }else{
            ans.push(currInterval);
            currInterval = intervals[i];
        }
    }

    ans.push(currInterval);
    return ans;
};