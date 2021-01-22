#include<bits/stdc++.h>

using namespace std;

vector<int> graph[10000];

std::vector<int> inDeg(10000);
std::vector<int> job(10000);


void addEdge(int u, int v) {
	graph[u].push_back(v);
	inDeg[v]++;
}


void solve(int n, int m) {
	queue<int> q;

	for (int i = 1; i < n + 1; ++i)
	{
		if (inDeg[i] == 0) {
			q.push(i);
			job[i] = 1;
		}
	}

	int curTime = 2;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int currJob = q.front();
			q.pop();
			for (int ngh : graph[currJob]) {
				inDeg[ngh]--;
				if (inDeg[ngh] == 0)q.push(ngh), job[ngh] = curTime;
			}
		}
		curTime++;

	}

	for (int i = 1; i < n + 1; ++i)
	{
		cout << job[i] << " ";
	}
}


int32_t main() {

	int n, m;
	n = 10;
	m = 13;

	// Given Directed Edges of graph
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 8);
	addEdge(2, 9);
	addEdge(3, 6);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(5, 8);
	addEdge(6, 7);
	addEdge(7, 8);
	addEdge(8, 10);

	// Function Call
	solve(n, m);
	return 0;
}