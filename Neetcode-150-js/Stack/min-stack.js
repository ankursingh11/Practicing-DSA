
// https://leetcode.com/problems/min-stack/description/

Array.prototype.back = function(){
    return this[this.length-1];
}
Array.prototype.empty = function(){
    return this.length === 0;
}

var MinStack = function() {
    this.stack = [];
    this.minStack = [Number.MAX_SAFE_INTEGER];
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    this.stack.push(val);
    if(val <= this.minStack.back()) this.minStack.push(val);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if(this.stack.empty()) return ;
    let val = this.stack.pop();
    if(val === this.minStack.back()) this.minStack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    if(this.stack.empty()) return;
    return this.stack.back();
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    if(this.minStack.back() === Number.MAX_SAFE_INTEGER) return;
    return this.minStack.back();
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */