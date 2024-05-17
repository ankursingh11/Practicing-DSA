
#include<bits/stdc++.h>

bool checkRedundantBrackets(string expression) {
	// Write your code here
	
	stack<char> st;
	int count = 0;
	for(auto ch : expression){
		if(ch != ')') st.push(ch);
		else{
			while(st.top() != '('){
				count++;
				st.pop();
				if(st.empty()) break;
			}

			if(st.empty()) break;
			if(count == 1) return true;

			if(count > 0){
				count = 0;
				st.pop();
			}else return true;
		}
	}

	return false;
}