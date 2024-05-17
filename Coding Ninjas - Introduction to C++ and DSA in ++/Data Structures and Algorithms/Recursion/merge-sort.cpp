

void merge(int *arr1, int size1, int *arr2, int size2, int *output){
    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2){
        if(arr1[i] <= arr2[j]) output[k++] = arr1[i++];
        else output[k++] = arr2[j++];
    }
    
    while(i < size1) output[k++] = arr1[i++];
    while(j < size2) output[k++] = arr2[j++];
}

void mergeSort(int input[], int size){
	// Write your code here
    if(size<=1) return;
    int size1 = size/2;
    int size2 = size - size1;
    
    int arr1[500], arr2[500];
    int i;
    for(i = 0; i < size1; i++) arr1[i] = input[i];
    for(int k = 0; i < size; k++, i++) arr2[k] = input[i];
    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    merge(arr1, size1, arr2, size2, input);
}
