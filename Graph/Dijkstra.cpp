#include<bits/stdc++.h>

using namespace std;

#define ff 				first
#define ss 				second
#define ll 				long long
#define pb 				push_back
#define mp 				make_pair
#define pii 			pair<int, int>
#define vi 				vector<int>
#define mii 			map<int, int>
#define setbits(x) 		__builtin_popcountll(x)
#define zrobits(x) 		__builtin_ctzll(x)
#define mod 			10000000007
#define inf 			1e18
#define ps(x, y) 		fixed<<setprecision(y)<<x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define all(x)			x.begin(), x.end()
#define rep(i,st,end)	for(ll i = st; i < end; i++)
#define rd(n)				ll n; cin >> n;
#define sz				size()


vector<vector<pii>> adj;


void dijkstra(vector<int>& dist, int s, int n, vi& p) {
	set<pii> q; // source, dist
	q.insert({0 , s});
	while (!q.empty()) {
		int u = q.begin() -> ss;
		q.erase(q.begin());

		for (auto x : adj[u]) {
			int v = x.ff;
			int wv = x.ss;
			if (dist[v] > dist[u] + wv) {
				q.erase({dist[v], v});
				dist[v] = dist[u] + wv;
				q.insert({dist[v], v});
				p[v] = u;
			}
		}
	}
}

// print the path from 1 to t
void printPath(vi& p, int t) {
	if (p[t] == -1) {
		cout << t << " ";
		return;
	}
	printPath(p, p[t]);
	cout << t << " ";
}


void solve() {
	rd(n); //  n is number of vertices
	rd(m);	// m is number of edges

	adj.resize(n + 1);
	rep(i, 0, m) {
		rd(u);
		rd(v);
		rd(wt);
		adj[u].pb(mp(v, wt));
		adj[v].pb(mp(u, wt));
	}

	vector<int> dist(n + 1, inf);
	dist[1] = 0;
	vi p(n + 1, -1);
	p[1] = -1;

	dijkstra(dist, 1, n, p);

	if (dist[n] == inf) {
		cout << -1 << endl;
		return;
	}
	printPath(p, n);

}


int32_t main() {
	solve();
	return 0;
}
