
int countDigits(int n){
	// Write your code here.	
    if(n == 0) return 0;
    return 1 + countDigits(n/10);
}