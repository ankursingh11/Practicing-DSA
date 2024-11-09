
// https://leetcode.com/problems/time-based-key-value-store/

var TimeMap = function() {
    this.map = {};
    this.maxEntries = 1000; // Set a reasonable cap for entries per key
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function(key, value, timestamp) {
    if (!this.map[key]) {
        this.map[key] = [];
    }
    
    // Check if we have reached max entries for the key, and remove the oldest entry if necessary
    if (this.map[key].length >= this.maxEntries) {
        this.map[key].shift(); // Remove the oldest entry
    }
    
    this.map[key].push([timestamp, value]);
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function(key, timestamp) {
    if (!this.map[key]) return "";
    
    let low = 0, high = this.map[key].length - 1;
    let ans = "";

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (this.map[key][mid][0] <= timestamp) {
            ans = this.map[key][mid][1];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
};

/** 
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */
