
// input - input array
// size - length of input array
// element - value to be searched

int binarySearch(int input[], int start, int end, int element){
    if(start > end) return -1;
    int mid = start + (end-start)/2;
    if(input[mid] == element) return mid;
    else if(input[mid] < element) return binarySearch(input, mid+1, end, element);
    else return binarySearch(input, start, mid-1, element);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    if(size == 0) return -1;
    int index = binarySearch(input, 0, size-1, element);

}
