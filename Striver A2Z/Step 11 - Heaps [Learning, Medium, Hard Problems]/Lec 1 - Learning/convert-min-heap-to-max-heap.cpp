
// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=convert-min-heap-to-max-heap

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i=(N/2)-1;i>=0;i--){
            heapify(arr,N,i);
        }
    }
    
    void heapify(vector<int> &arr, int N,int i){    
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
            if(arr[largest]<arr[left] && left<N){
                largest=left;
            }
            if(arr[largest]<arr[right] && right<N){
                largest=right;
            }
            if(largest!=i) {
                swap(arr[i],arr[largest]);
                if(largest<=N/2-1) heapify(arr, N, largest);
            }
            
        }
    
};