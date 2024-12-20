
// Bipartite Graph 
// - You can divide all vertices of graph in 2 sets such that all vertices of graphs are from set 1 to set 2
// Not Bipartite if graph has a cycle or graph has odd number of nodes


#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[],int node,int *visited,int parent, int color){
	//come to node
	visited[node] = color; //1 or 2, both mean visited

	for(auto nbr : graph[node]){

		if(visited[nbr]==0){
			int subprob = dfs_helper(graph,nbr,visited,node,3-color);
			
			if(subprob==false){
				return false;
			}

		}
		else if(nbr!=parent and color==visited[nbr]){
			return false;
		}

	}
	return true;
}


bool dfs(vector<int> graph[],int N){

	int visited[N] = {0};  // 0- Not Visited, 1 - Visited and color is 1, 2 - Visted and color is 2

	int color = 1;
	int ans = dfs_helper(graph,0,visited,-1,color);
	//later one

	//colors
	for(int i=0;i<N;i++){
		cout<<i<<" - Color "<<visited[i] <<endl;
	}

	//
	return ans;
}


int main(){
	int N,M;

	cin>>N>>M;

	vector<int> graph[N];
	while(M--){
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	//BFS or DFS, by coloring the nodes at each step (current node has color 1, nbr should have a color 2)
	if(dfs(graph,N)){
		cout<<"Yes its bipartite";
	}
	else{
		cout<<"Not bipartite";
	}



	return 0;
}

