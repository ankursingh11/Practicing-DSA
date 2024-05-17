
// Change in the given string itself. So no need to return or print anything
#include<cstring>

void removeX(char input[]) {
    // Write your code here
    if(input[0] == '\0') return;
    removeX(input+1);
    
    if(input[0] == 'x'){
        int len = strlen(input);
        for(int i = 0; i < len-1; i++) input[i] = input[i+1];
        
        input[len-1] = '\0';
    }
}
