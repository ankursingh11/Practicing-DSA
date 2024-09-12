
// https://leetcode.com/problems/valid-parentheses/

/**
 * @param {string} s
 * @return {boolean}
 */
const OPENING = ['(', '{', '['];

Array.prototype.empty = function(){
  return this.length === 0;
}

Array.prototype.back = function(){
  return this[this.length-1];
}

var isValid = function(s) {
    let len = s.length;
    
    const stack = [];
    for(let i = 0; i < len; i++){
      let curr = s[i];
      if(OPENING.includes(curr)){
        stack.push(curr);
      }
      // it is a closing bracket
      else{
        if(stack.empty()) return false;
        else if(curr === ')' && stack.back() != '(') return false;
        else if(curr === '}' && stack.back() != '{') return false;
        else if(curr === ']' && stack.back() != '[') return false;
        stack.pop();
      }
    }
    
    if(!stack.empty()) return false;
    return true;
};