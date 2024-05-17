

void helper(int input[], int size, int x, int output[], int &k, int pos){
    if(size == 0) return;
    if(input[0] == x){
        output[k++] = pos;
    }
    helper(input+1, size-1, x, output, k, pos+1);
}


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    int k = 0;
    helper(input, size, x, output, k, 0);
    return k;

}
