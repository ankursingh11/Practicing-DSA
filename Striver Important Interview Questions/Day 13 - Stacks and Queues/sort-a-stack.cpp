
// https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void sortStack(stack<int>&stack, int ele){

	if(stack.empty() || ele >= stack.top()){
		stack.push(ele);
		return;
	}

	int topElement = stack.top();
	stack.pop();
	sortStack(stack, ele);
	stack.push(topElement);
	return;
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.size() == 1) return;

	int topElement = stack.top();
	stack.pop();
	sortStack(stack);
	sortStack(stack, topElement);
	return;
}