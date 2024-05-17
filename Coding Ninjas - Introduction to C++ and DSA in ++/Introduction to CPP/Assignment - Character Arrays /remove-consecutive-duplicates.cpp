// input - given string
// You need to update in the input string itself. No need to return or print anything

#include<bits/stdc++.h>

void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    int size = strlen(input);
    char current = input[0];
    
    int i = 1, j = 1;
    for( ; i < size; i++){
        if(input[i] != current){
            current = input[i];
            swap(input[i], input[j]);
            j++;
        }
    }

    input[j] = '\0';

}
