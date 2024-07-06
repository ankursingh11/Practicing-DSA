
// https://leetcode.com/problems/course-schedule/description/


class Graph{
    int V;
    list<int>*l;

    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    bool canFinishHelper(int source, vector<bool>&visited, vector<bool>&stack){
        visited[source] = true;
        stack[source] = true;

        for(auto nbr : l[source]){
            if(stack[nbr]) return true;
            else if(!visited[nbr]){
                bool nbrFoundACycle = canFinishHelper(nbr, visited, stack);
                if(nbrFoundACycle) return true;
            }
        }

        stack[source] = false;
        return false;
    }

    bool canFinish(){
        vector<bool> visited(V, false), stack(V, false);

        for(int i = 0; i < V; i++){
            if(canFinishHelper(i, visited, stack)) return false;
        }

        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        Graph g(numCourses);

        for(auto ele : prerequisites){
            int x = ele[0], y = ele[1];
            g.addEdge(y, x);
        }

        return g.canFinish();
    }
};