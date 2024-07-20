
// https://leetcode.com/problems/course-schedule/

class Graph{
    int V;
    list<int>* l;

    public :
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    bool checkCycle(int node, vector<bool>&visited, vector<bool>&stack){
        visited[node] = true;
        stack[node] = true;

        for(auto nbr : l[node]){
            if(stack[nbr]) return true;
            else if(!visited[nbr]){
                bool nbrHasCycle = checkCycle(nbr, visited, stack);
                if(nbrHasCycle) return true;
            }
        }

        stack[node] = false;
        return false;
    }

    bool canFinish(){
        vector<bool> visited(V, false), stack(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool hasCycle = checkCycle(i, visited, stack);
                if(hasCycle) return false;
            }
        }
    
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        Graph g(numCourses);

        for(auto ele : prerequisites){
            g.addEdge(ele[1], ele[0]);
        }

        return g.canFinish();
    }
};