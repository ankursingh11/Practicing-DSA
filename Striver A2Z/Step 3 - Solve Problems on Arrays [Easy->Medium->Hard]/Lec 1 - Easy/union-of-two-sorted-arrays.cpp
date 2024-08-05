
// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> v(n+m);
        n = unique(arr1, arr1+n) - arr1;
        m = unique(arr2, arr2+m) - arr2;
        auto it = set_union(arr1, arr1+n, arr2, arr2+m, v.begin());
        v.resize(it-v.begin());
        return v;
    }
};