
// https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 

void sortStack(stack<int> &st, int ele){
	if(st.empty() || ele >= st.top()){
		st.push(ele);
		return;
	}

	int topEle = st.top();
	st.pop();
	sortStack(st, ele);
	st.push(topEle);
	return;
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;

	int topEle = stack.top();
	stack.pop();

	sortStack(stack);
	sortStack(stack, topEle);
	return;
}