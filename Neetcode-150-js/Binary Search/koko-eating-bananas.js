
// https://leetcode.com/problems/koko-eating-bananas/

/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */

var canFinish = function(piles, h, eatingSpeed){
    let time = 0;
    for(let i = 0; i < piles.length; i++){
        time += Math.ceil(piles[i]/eatingSpeed);
    }

    console.log("time", time);
    return (time <= h) ? true : false;
}

var minEatingSpeed = function(piles, h) {
    
    // let start = Math.min(...piles);
    let start = 1;
    let end = Math.max(...piles);

    while(start < end){
        let mid = Math.floor((start+end)/2);
        console.log(start, end, mid);
        if(canFinish(piles, h, mid)) end = mid;
        else start = mid+1;
    }

    return start;
};