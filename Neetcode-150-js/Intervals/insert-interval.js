
// https://leetcode.com/problems/insert-interval/

/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let len = intervals.length;
    const ans = [];
    // if(len === 0) return ans;

    let i = 0;

    // put in all those ranges which are smaller than the new interval
    while(i < len && intervals[i][1] < newInterval[0]) ans.push(intervals[i++]);

    // encounter those ranges which fall into the interval
    while(i < len && intervals[i][0] <=  newInterval[1]){
        newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
        newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push(newInterval);

    // put in all thise ranges which are greater than the new Interval
    while(i < len) ans.push(intervals[i++]);

    return ans;
};