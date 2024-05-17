
// Change in the given string itself. So no need to return or print the changed string.
#include<cstring>
void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0') return;
    pairStar(input+1);
    if(input[0] == input[1]){
        int len = strlen(input);
        input[len+1] = '\0';
        for(int i = len; i>1; i--) input[i] = input[i-1];
        input[1] = '*';
    }
}
