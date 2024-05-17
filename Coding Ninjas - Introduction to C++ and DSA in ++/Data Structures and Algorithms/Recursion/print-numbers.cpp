

void print_helper(int a, int n){
    if(a > n) return;
    cout<<a++<<" ";
    print_helper(a, n);
}

void print(int n){
    print_helper(1, n)
}