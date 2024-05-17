

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array
#include<bits/stdc++.h>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    sort(input1, input1+size1);
    sort(input2, input2+size2);
    
    int i = 0, j = 0;
    while(i < size1 && j < size2){
        if(input1[i] < input2[j]) i++;
        else if(input1[i] > input2[j]) j++;
        else{
            cout<<input1[i]<<endl;
            i++;
            j++;
        }
        
    }

}
