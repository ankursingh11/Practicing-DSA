

int partition(int input[], int si, int ei){
    int pivot = input[si];
    
    int count = 0;
    for(int i = si+1; i<=ei; i++) if(input[i] <= pivot) count++;
    
    int pi = si+count;
    
    int temp = input[si];
    input[si] = input[pi];
    input[pi] = temp;
    
    int i = si, j = ei;
    while(i<=pi && j>=pi){
        while(input[i] <= pivot) i++;
        while(input[j] > pivot) j--;
        if(i < pi && j > pi){
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    
    return pi;
}

void quickSort(int input[], int si, int ei){
    if(si>=ei) return;
    int pi = partition(input, si, ei);
    quickSort(input, si, pi-1);
    quickSort(input, pi+1, ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size<=1) return;
    quickSort(input, 0, size-1);
}
