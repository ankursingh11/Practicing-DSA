

// arr - input array
// size - size of array

int DuplicateNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int n = size-2;
    int a = (n*(n+1))/2;
    int b = 0;
    for(int i = 0; i < size; i++) b+=arr[i];
    return b-a;
    

}