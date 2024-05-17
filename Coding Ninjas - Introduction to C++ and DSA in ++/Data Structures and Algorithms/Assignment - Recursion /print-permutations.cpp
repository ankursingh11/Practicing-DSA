
#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, int l, int r){
	if(l == r){
		cout<<input<<endl;
	}
	for(int i = l; i <= r; i++){
		swap(input[l], input[i]);
		printPermutations(input, l+1, r);
		swap(input[l], input[i]);
	}

	return;
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	int size = input.size();
	if(size == 0) return;

	printPermutations(input, 0, size-1);
	return;
}
