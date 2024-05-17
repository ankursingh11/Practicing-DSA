// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.

#include<bits/stdc++.h>

string getCompressedString(string input) {
    // Write your code here

    int size = input.size();
    string ans = "";
    if(size == 0) return ans;
    
    int i = 0, j = 0;
    while(i < size){
        // modulate
        char current = input[i++];
        int countOfCurrent = 1;
        while(current == input[i]){
            countOfCurrent++;
            i++;
        }

        // compress
        ans += current;
        j++;
        if(countOfCurrent > 1){
            ans += to_string(countOfCurrent);
            j++;
        }
    }

    return ans;
}
