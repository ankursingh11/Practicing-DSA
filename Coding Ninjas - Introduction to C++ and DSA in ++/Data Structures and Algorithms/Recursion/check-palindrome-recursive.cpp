

#include<cstring>

bool helper(char input[], int si, int ei){
    if(si>=ei) return true;
    if(input[si] != input[ei]) return false;
    return helper(input, si+1, ei-1);
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int si = 0;
    int ei = strlen(input)-1;
    return helper(input, si, ei);
}
