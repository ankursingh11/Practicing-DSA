
// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

void findLPS(vector<int>&lps, string pattern){
    int i = 1;
    int len = 0;
    
    while(i < pattern.size()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0) len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}


int Solution::solve(string s) {
    
    int n = s.size();
    int k = n;
    
    string text = s;
    reverse(text.begin(), text.end());
    s = s + "#" + text;
    n = s.size();
    vector<int> lps(n, 0);
    findLPS(lps, s);
    
    return k - lps[n-1];
}
