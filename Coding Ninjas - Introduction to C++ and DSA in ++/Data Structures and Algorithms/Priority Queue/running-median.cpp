

#include<bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < n; i++){
        int ele = arr[i];

        // insertion
        if(maxHeap.size() && ele > maxHeap.top()) minHeap.push(ele);
        else maxHeap.push(ele);

        // balancing
        if(abs(maxHeap.size() - minHeap.size()) > 1){
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        // finding median
        int totalSize = maxHeap.size() + minHeap.size();
        int ans = 0;
        if(totalSize %2 != 0){
            if(maxHeap.size() > minHeap.size()) ans = maxHeap.top();
            else ans = minHeap.top();
        }else{
            if(maxHeap.size()) ans += maxHeap.top();
            if(minHeap.size()) ans += minHeap.top();
            ans = ans/2;
        }

        cout<<ans<<" ";
    }

    return;
}