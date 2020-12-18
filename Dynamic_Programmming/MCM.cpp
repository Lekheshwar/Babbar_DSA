#include<bits/stdc++.h>

using namespace std;

#define ff 				first
#define ss 				second
#define int 			long long
#define pb 				push_back
#define mp 				make_pair
#define pii 			pair<int, int>
#define vi 				vector<int>
#define mii 			map<int, int>
#define setbits(x) 		__builtin_popcountll(x)
#define zrobits(x) 		__builtin_ctzll(x)
#define mod 			10000000007
#define INF 			1e18
#define ps(x, y) 		fixed<<setprecision(y)<<x
#define tc(x) 			int x; cin>>x; while(x--)
#define endl 			"\n"
#define rep(i, st, k)    for(int i = st; i < k; i++)
#define all(x)			x.begin(), x.end()
#define dbg(x)			cout<<x<<endl;

int dp[101][101];

int MCM(vi& v, int left, int right) {
	if (left == right)
		return dp[left][right] = 0;

	if (dp[left][right] != -1)return dp[left][right];

	int res = INT_MAX;

	for (int i = left; i < right; i++) {
		int temp = MCM(v, left, i) + MCM(v, i + 1, right) + v[left - 1] * v[i] * v[right];
		res = min(res, temp);
	}
	return dp[left][right] = res;
}


void solve() {
	int n;
	cin >> n;
	std::vector<int> v(n);
	rep(i, 0, n)cin >> v[i];
	memset(dp, -1, sizeof dp);
	cout << MCM(v, 1, n - 1);
}


int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t; while (t--)
	solve();
	return 0;
}
