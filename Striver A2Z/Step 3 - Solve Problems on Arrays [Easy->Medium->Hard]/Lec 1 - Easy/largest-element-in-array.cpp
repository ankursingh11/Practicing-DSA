
// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int largestEle = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > largestEle) largestEle = arr[i];
        }
        return largestEle;
    }
};