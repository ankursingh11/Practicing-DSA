

#include<bits/stdc++.h>

void rotate(int *input, int d, int n)
{
    //Write your code here
    reverse(input.begin(), input.end());
    reverse(input.begin(), input.begin()+(n-d));
    reverse(input.begin()+(n-d), input.end());
    return;
}