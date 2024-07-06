
// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> result(m+n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result[i+j] += (num1[i]-'0')*(num2[j]-'0');
                result[i+j+1] += result[i+j]/10;
                result[i+j] = result[i+j]%10;
            }
        }

        string ans;
        for(int i = result.size()-1; i >= 0; i--){
            if(!ans.empty() || result[i] != 0) ans.push_back(result[i]+'0');
        }

        return ans.empty() ? "" : ans;
    }
};