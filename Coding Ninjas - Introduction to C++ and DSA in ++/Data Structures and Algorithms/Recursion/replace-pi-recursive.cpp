
// Change in the given string itself. So no need to return or print anything
#include<cstring>

void replacePi(char input[]) {
	// Write your code here
    if(input[0] == '\0') return;
    replacePi(input+1);
    
    if(input[0] == 'p' && input[1] == 'i'){
        int len = strlen(input);
        input[len+2] = '\0';
        for(int i = len-1; i>1; i--) input[i+2] = input[i];
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}
