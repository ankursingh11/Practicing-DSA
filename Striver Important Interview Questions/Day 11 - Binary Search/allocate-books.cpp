
// https://www.interviewbit.com/problems/allocate-books/

bool isPossible(vector<int>&A, int B, int pages){
    int count = 0;
    int sumAllocated = 0;
    for(int i = 0; i < A.size(); i++){
        if(sumAllocated + A[i] > pages){
            count++;
            sumAllocated = A[i];
            if(sumAllocated > pages) return false;
        }else sumAllocated += A[i];
    }
    
    if(count < B) return true;
    return false;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    
    int low = A[0], high = 0;
    for(auto ele : A){
        low = min(low, ele);
        high = high + ele;
    }
    
    while(low <= high){
        int mid = (low + high)>>1;
        if(isPossible(A, B, mid)) high = mid - 1;
        else low = mid + 1;
    }
    
    return low;
}