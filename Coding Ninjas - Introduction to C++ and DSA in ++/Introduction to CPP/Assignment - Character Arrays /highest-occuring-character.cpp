// input - given string

#include<bits/stdc++.h>

char highestOccurringChar(char input[]) {
    // Write your code here

    int size = strlen(input);
    unordered_map<char, int> mp;
    for(int i = 0; i < size; i++){
        mp[input[i]]++;
    }

    int highestCount = mp[input[0]];
    char highestCountCharacter = input[0];
    for(int i = 1; i < size; i++){
        if(mp[input[i]] > highestCount){
            highestCount = mp[input[i]];
            highestCountCharacter = input[i];
        }
    }

    return highestCountCharacter;

}
