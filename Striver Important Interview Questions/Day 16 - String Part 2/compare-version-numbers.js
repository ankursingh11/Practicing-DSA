
// https://leetcode.com/problems/compare-version-numbers/description/

/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let v1 = version1.split('.').map(Number);
    let v2 = version2.split('.').map(Number);

    let i = 0;
    while(i < v1.length || i < v2.length){
        let a = (i < v1.length) ? v1[i] : 0;
        let b = (i < v2.length) ? v2[i] : 0;

        if(a < b) return -1;
        else if(a > b) return 1;
        i+=1;
    }

    return 0;
    
};