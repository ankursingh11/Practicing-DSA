
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

    int solve(int num, vector<string>&output, vector<string>&keypad){
        if(num == 0){
            output.push_back("");
            return 1;
        }

        int lastDigit = num%10;
        vector<string> arr;
        int count = solve(num/10, arr, keypad);
        string option = keypad[lastDigit];
        
        int k = 0;
        
        for(int i = 0; i < option.size(); i++){
            for(int j = 0; j < count; j++){
                output.push_back(arr[j] + option[i]);
                k++;
            }
        }

        return k;
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits == "") return ans;

        int num = stoi(digits);
        vector<string> output;
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(num, output, keypad);

        return output;
    }
};