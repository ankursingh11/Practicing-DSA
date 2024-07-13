
// https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION


int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        // cout<<low<<" "<<high<<endl;

        int midN = (low + high) / 2;
        // int midN = func(mid, n, m);

        // cout<<midN<<" "<<pow(midN, n)<<endl;

        if (pow(midN,n) == m) {
            return midN;
        }
        else if (pow(midN, n) < m) low = midN + 1;
        else high = midN - 1;

        // cout<<low<<" "<<high<<endl;
        // cout<<"---------------";
    }
    return -1;
}