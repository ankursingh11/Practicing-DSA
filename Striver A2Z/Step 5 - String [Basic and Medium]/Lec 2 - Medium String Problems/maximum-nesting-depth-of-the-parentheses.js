
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(str) {
    const st = [];
    let ans = 0;
    for(let ele of str){
      if(ele === "("){
        st.push(ele);
        ans = Math.max(ans, st.length);
      }else if(ele === ")") st.pop();
    }
    
    return ans;
};