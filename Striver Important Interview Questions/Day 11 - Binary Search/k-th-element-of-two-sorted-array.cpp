
// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int size1, int size2, int k)
    {
        
        if(size1 > size2) return kthElement(arr2, arr1, size2, size1, k);
        
        int low = max(0, k-size2);
        int high = min(k, size1);
        
        while(low <= high){
            int cut1 = (low + high)/2;
            int cut2 = k - cut1;
            
            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
            
            int right1 = (cut1 == size1) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == size2) ? INT_MAX : arr2[cut2];
            
            if(left1 <= right2 && left2 <= right1) return max(left1, left2);
            else if(left1 > right2) high = cut1-1;
            else low = cut1+1;
        }
        
        return 1;
    }
};