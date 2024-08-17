
// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        if(!head) return ans;
        Node*curr = head;
        while(curr->next) curr = curr->next;
        
        Node*start = head;
        Node*last = curr;
        while(start->data < last->data){
            int currSum = start->data + last->data;
            if(currSum == target){
                ans.push_back({start->data, last->data});
                start = start->next;
                last = last->prev;
            }else if(currSum > target) last = last->prev;
            else start = start->next;
        }
        return ans;
    }
};