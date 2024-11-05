
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

/**
 * @param {string[]} tokens
 * @return {number}
 */

const OPERATORS = ['+', '-', '*', '/'];

var evalRPN = function(tokens) {
    let len = tokens.length;
    let result = 0;
    if(len === 0) return result;

    const stack = [];
    for(let i = 0; i < len; i++){
        let val = tokens[i];
        if(OPERATORS.includes(val)){
            let a = stack.pop();
            let b = stack.pop();

            if(val === '+') result = a+b;
            if(val === '-') result = b-a;
            if(val === '*') result = a*b;
            if(val === '/') result = Math.trunc(b/a);

            stack.push(result);
        }else stack.push(+val);
    }


    return stack.pop();
};