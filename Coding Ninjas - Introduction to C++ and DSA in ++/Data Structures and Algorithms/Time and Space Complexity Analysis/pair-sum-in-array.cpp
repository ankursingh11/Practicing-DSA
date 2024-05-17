


#include<bits/stdc++.h>
using namespace std;


void pairSum(int input[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    sort(input, input+size);
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++) m[input[i]]+=1;
    
    int i =  0, j = size-1;
    while(i<j){
        if(input[i] + input[j] < x) i++;
    	if(input[i] + input[j] > x) j--;
        if(input[i] + input[j] == x){
            int a = m[input[i]];
            int b = m[input[j]];
            int count;
            if(j-i+1 == a){
                count = (a*(a-1))/2;
                for(int k = 0; k < count; k++) cout<<input[i]<<" "<<input[j]<<endl;
            }
            else{
                count = a*b;
            	for(int k = 0; k < count; k++) cout<<input[i]<<" "<<input[j]<<endl;
            }
            i+=a;
            j-=b;
        }
    }
    
    

}
