
// https://leetcode.com/problems/non-overlapping-intervals/

/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
    let count = 0;
    let len = intervals.length;
    if(len === 0) return count;

    intervals = intervals.sort((a, b) => a[1] - b[1]);
    let prev = intervals[0];
    for(let i = 1; i < len; i++){
        if(prev[1] > intervals[i][0]) count++;
        else prev = intervals[i];
    }

    return count;
};