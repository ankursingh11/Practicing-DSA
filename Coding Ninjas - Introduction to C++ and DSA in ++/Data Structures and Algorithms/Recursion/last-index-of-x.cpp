
int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if(size == 0) return -1;
    int ans = lastIndex(input+1, size-1, x);
    if(input[0] == x && ans == -1) return 0;
    if(ans == -1) return ans;
    return ans +1 ;
}
