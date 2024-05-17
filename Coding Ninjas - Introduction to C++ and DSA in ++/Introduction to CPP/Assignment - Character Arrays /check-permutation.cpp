

// input1 - first input string
// input2 - second input string

#include<bits/stdc++.h>

bool isPermutation(char input1[], char input2[]) {
    // Write your code here

    char arr[256]{0};
    int size1 = strlen(input1);

    for(int i = 0; i < size1; i++){
        arr[input1[i]]++;
    }

    int size2 = strlen(input2);

    for(int i = 0; i < size2; i++){
        arr[input2[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if(arr[i] != 0) return false;
    }
    
    return true;
}
