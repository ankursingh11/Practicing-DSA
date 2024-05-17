
// input - given string
// You need to remove all occurrences of character c that are present in string input.
// Change in the input itself. So no need to return or print anything.

#include<bits/stdc++.h>

void removeAllOccurrencesOfChar(char input[], char c) {
    // Write your code here

    int size = strlen(input);
    int i = 0, j = 0;
    for( ; i < size; i++){
        if(input[i] != c){
            swap(input[i], input[j]);
            j++;
        }
    }
    input[j] = '\0';

    return;

}
