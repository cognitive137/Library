#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


class Graph {
public:
	int v; // no of vertices
	list<int> *adj; // array of linked list -> adjacency list
	// constrcutror
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}
 
	// adds an edge between vertex u and v
	void addEdge(int u, int v, bool bidir = true) { 
		// if bidir == true -> graph is undirected
		// insert at last to the list storing neighbours of u
		adj[u].push_back(v); 
		if(bidir) {
			adj[v].push_back(u);
		}
	}
 
	void bfsHelper(int src, bool *visited) {
		queue<int> qu;
		qu.push(src);
		visited[src] = true;
		while(not qu.empty()) {
			int curr = qu.front();
			cout<<curr<<" ";
			qu.pop();
			for(int neighbour: adj[curr]) {
				if(not visited[neighbour]) {
					qu.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void BFS() {
		bool *visited = new bool[this->v]();
		for(int i = 0; i < this->v; i++) {
			if(visited[i] == false) {
				bfsHelper(i, visited);
			}
		}
		delete [] visited;
	}
 
	// int noOfCC() {
	// 	int count = 0;
	// 	unordered_set<int> visited;
	// 	for(int i = 0; i < this->v; i++) {
	// 		if(visited.count(i) == 0) {
	// 			count++;
	// 			bfsHelper(i, visited);
	// 		}
	// 	}
	// 	return count;
	// }
};
 
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	Graph g(n);
	int e; // no of edges
	cin>>e;
	while(e--) {
		int u, v;
		cin>>u>>v;
		g.addEdge(u, v);
	}
	g.BFS();
 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}