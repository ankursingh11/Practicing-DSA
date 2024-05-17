
#include<cstring>

int stringToNumber(char input[]) {
    // Write your code here
    int ans = 0;
    int len = strlen(input);
    for(int i = 0, pow = 10; i < len; i++){
        int curr = input[i] - '0';
        ans = ans*pow + curr;
    }
    return ans;
}


