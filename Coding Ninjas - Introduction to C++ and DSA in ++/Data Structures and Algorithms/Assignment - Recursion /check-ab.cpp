
#include<bits/stdc++.h>

bool checkAB(char input[]) {
	// Write your code here
    if(input[0] == '\0') return true;
    if(input[0]!='a') return false;
    if(input[1]!='\0' && input[2]!='\0'){
        if(input[1] == 'b' && input[2] == 'b') return checkAB(input+3);
    }
    return checkAB(input+1);
}
