
bool isMaxHeap(int arr[], int n) {
    // Write your code here

    for(int i = 0; i < n; i++){
        int leftChildIndex = 2*i+1;
        if(leftChildIndex < n && arr[i] < arr[leftChildIndex]) return false;
        int rightChildIndex = 2*i+2;
        if(rightChildIndex < n && arr[i] < arr[rightChildIndex]) return false; 
    }

    return true;
}