
// https://leetcode.com/problems/course-schedule-ii/

class Graph{
    int V;
    list<int> *l;

    public :
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    bool hasCycleUtil(int node, vector<bool>&visited, vector<bool>&stack){
        visited[node] = true;
        stack[node] = true;

        for(auto nbr : l[node]){
            if(stack[nbr] == true) return true;
            else if(!visited[nbr]){
                bool nbrHasACycle = hasCycleUtil(nbr, visited, stack);
                if(nbrHasACycle) return true;
            }
        }

        stack[node] = false;
        return false;
    }

    bool hasCycle(){
        vector<bool> visited(V, false), stack(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(hasCycleUtil(i, visited, stack)) return true;
            }
        }
        return false;
    }

    void findPathUtil(int node, vector<bool>&visited, vector<int>&ans){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]) findPathUtil(nbr, visited, ans);
        }

        ans.push_back(node);
    }

    void findPath(vector<int> &ans){
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                findPathUtil(i, visited, ans);
            }
        }
    }


};


class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> ans;
        if(numCourses == 0) return ans;

        Graph g(numCourses);

        for(auto ele : prerequisites){
            g.addEdge(ele[1], ele[0]);
        }

        if(g.hasCycle()) return ans;

        g.findPath(ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};