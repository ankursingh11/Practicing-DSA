
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool helper(unordered_map<int, vector<int>*>AL, int v1, int v2, unordered_map<int, bool>&visited){
    vector<int>*list = AL[v1];
    for(int i = 0; i < list->size(); i++){
        if(list->at(i) == v2) return true;
    }
    
    visited[v1] = true;
    for(int i = 0; i < list->size(); i++){
        if(visited.count(list->at(i)) == 0) return helper(AL, list->at(i), v2, visited);
    }
    return false;
}


bool hasPath(unordered_map<int, vector<int>*>AL, int v1, int v2){
    unordered_map<int, bool>visited;
    return helper(AL, v1, v2, visited);
}

int main() {
    int V, E;
    cin >> V >> E;
    
    unordered_map<int, vector<int>*> AL;
    for(int i = 0; i < V; i++){
        vector<int>*v = new vector<int>();
        AL[i] = v;
    }
    
    for(int i = 0; i < E; i++){
        int s,e;
        cin>>s>>e;
        AL[s]->push_back(e);
        AL[e]->push_back(s);
    }
    
    int v1, v2;
    cin>>v1>>v2;
    
    if(hasPath(AL, v1, v2)) cout<<"true";
    else cout<<"false";
    
  return 0;
}
