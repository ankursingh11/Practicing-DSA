
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int, bool> visitedElements;
    unordered_map<int, int> m; //elementToIndexMapping
    
    for(int i = 0; i < n; i++){
        m[arr[i]] = i;
        if(visitedElements.count(arr[i]) == 0) visitedElements[arr[i]] = true;
    }
    
    int ansLength = 1;
    int ansIndex = 0;
    
    for(int i = 0; i < n; i++){
        
        int temp = arr[i];
        int currMinStartIndex = i;
        int count = 0;
        int tempNum = temp;
        
        //forward
        while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true){
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }
        
        //backWard
        tempNum = temp-1;
         while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true){
             visitedElements[tempNum] = false;
             count++;
             currMinStartIndex = m[tempNum];
             tempNum--;
         }
        
        if(count > ansLength){
            ansLength = count;
            ansIndex = currMinStartIndex;
        }else if(count == ansLength){
            if(currMinStartIndex < ansIndex){
                ansIndex = currMinStartIndex;
            }
        }
    }
    
    int num = arr[ansIndex];
    vector<int>ans;
    ans.push_back(num);
    ansLength--;
    
    while(ansLength!=0){
        num++;
        ans.push_back(num);
        ansLength--;
    }
    
    return ans;
    
}
