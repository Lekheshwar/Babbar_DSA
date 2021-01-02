#include<bits/stdc++.h>

using namespace std;

class Graph {
private:
	int V; // Stores the number of vertices

	vector<vector<int>> adj; // Edges

	void DFSUtil(int v, bool vis[]) {

		vis[v] = true;
		cout << v << " ";
		for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
			if (!vis[*it]) {
				DFSUtil(*it, vis);
			}
		}

	}

public:
	Graph(int v) {
		this->V = v;
		adj.resize(V);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void dfs(int src) {
		bool vis[V] = {false};

		/* In case of diconnected components. Call the DFSUtil() function for all the
			unvisited nodes*/

		DFSUtil(src, vis);
	}
};



void solve() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.dfs(2);
	return;
}


int32_t main() {
	solve();
	return 0;
}