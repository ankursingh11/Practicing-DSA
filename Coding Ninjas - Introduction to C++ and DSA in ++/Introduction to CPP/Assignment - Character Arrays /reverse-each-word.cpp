// input - given string
// Update in the given input itself. No need to return or print anything

#include<bits/stdc++.h>

void reverseHelper(char input[], int i, int j){
    while(i < j){
        swap(input[i++], input[j--]);
    }
}

void reverseEachWord(char input[]) {
    // Write your code here

    int size = strlen(input);
    int i = 0, j = 0;
    for( ; j < size; j++){
        if(input[j] == ' '){
            reverseHelper(input, i, j-1);
            i = j+1;
        }
    }

    reverseHelper(input, i, j-1);
    return;
}
