
// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            int currSum = digits[i] + carry;
            carry = currSum/10;
            digits[i] = currSum%10;
        }

        if(carry > 0) digits.insert(digits.begin(), carry);

        return digits;
    }
};