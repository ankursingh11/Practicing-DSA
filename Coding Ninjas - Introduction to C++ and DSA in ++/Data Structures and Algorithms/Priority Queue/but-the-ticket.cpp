
#include<bits/stdc++.h>

int buyTicket(int *arr, int n, int k) {
    // Write your code here

    priority_queue<int> pq;
    queue<int> q;
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
        q.push(arr[i]);
    }

    int count = 0;
    while(!pq.empty()){
        if(pq.top() == q.front()){
            if(k == 0) return (1+count);
            pq.pop();
            q.pop();
            k--;
            count++;
        }else{
            q.push(q.front());
            q.pop();
            if(k == 0) k = q.size()-1;
            else k--;
        }
    }

    return count;
}