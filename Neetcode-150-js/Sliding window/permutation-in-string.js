
// https://leetcode.com/problems/permutation-in-string/

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */

var check = (arr1, arr2) => {
    for(let i = 0; i < 26; i++){
        if(arr1[i] !== arr2[i]) return false;
    }
    return true;
}

var checkInclusion = function(s1, s2) {
    s1 = s1.toLowerCase();
    s2 = s2.toLowerCase();

    const freq1 = Array.from({length : 26}, () => 0);
    for(let i = 0; i < s1.length; i++){
        let index = s1.charCodeAt(i)-97;
        freq1[index]++;
    }
    
    const freq2 = Array.from({length : 26}, ()=>0);
    let i = 0, j = 0;
    while(j < s2.length){
        let index = s2.charCodeAt(j)-97;
        freq2[index]++;
        let windowSize = (j-i+1);

        if(windowSize === s1.length){
            if(check(freq1, freq2)) return true;
        }

        if(windowSize < s1.length) j++;
        else{
            let index = s2.charCodeAt(i)-97;
            freq2[index]--;
            i++;
            j++;
        }
    }
    return false;
};