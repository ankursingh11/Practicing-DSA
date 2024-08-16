
// https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sortStack(stack<int>&st, int ele){
    if(st.empty() || ele >= st.top()){
        st.push(ele);
        return;
    }
    int x = st.top();
    st.pop();
    sortStack(st, ele);
    st.push(x);
    return;
}

void SortedStack :: sort()
{
   if(s.size() == 1){
       return;
   }
   
   int ele = s.top();
   s.pop();
   sort();
   sortStack(s, ele);
   return;
}