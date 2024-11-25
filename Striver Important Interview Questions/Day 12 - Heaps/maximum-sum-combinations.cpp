
// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ASize = A.size();
    int BSize = B.size();
    
    priority_queue<pair<int, pair<int, int>>> pq;
    set <pair<int, int>> my_set;
    vector<int> ans;
    pq.push({A[ASize-1] + B[BSize-1] , {ASize-1, BSize-1}});
    my_set.insert({ASize-1, BSize-1});
    
    for(int k = 0; k < C; k++){
        auto temp = pq.top();
        pq.pop();
        
        ans.push_back(temp.first);
        int i = temp.second.first;
        int j = temp.second.second;
        
        if(i-1 >= 0){
            int currSum = A[i-1] + B[j];
            auto currPair = make_pair(i-1, j);
            if(my_set.find(currPair) == my_set.end()){
                pq.push({currSum, currPair});
                my_set.insert(currPair);
            }
        }
        
        if(j-1 >= 0){
            int currSum = A[i] + B[j-1];
            auto currPair = make_pair(i, j-1);
            if(my_set.find(currPair) == my_set.end()){
                pq.push({currSum, currPair});
                my_set.insert(currPair);
            }
        }
    }
    
    return ans;
}
