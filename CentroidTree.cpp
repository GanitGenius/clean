#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
#define fi first
#define se second
#define pb push_back
const int maxn = 5e5 + 5;

int n, sz[maxn];
vector<int> T[maxn];
bool used[maxn];

void computeSz(int v, int p) {
	sz[v] = 1;
	for (auto u : T[v])if (!used[u] && u != p)
		computeSz(u, v), sz[v] += sz[u];
}
int centroid(int v, int lim, int p) {
	for (auto u : T[v])if (!used[u] && u != p) {
		if (sz[u] > lim)
			return centroid(u, lim, v);
	}
	return v;
}
void centroidDec(int v) {
	computeSz(v, v);
	int c = centroid(v, sz[v] / 2, v);
	used[c] = true;
	for (auto u : T[c])if (!used[u])
		centroidDec(u);
}

int main() {
	// ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		T[u].pb(v), T[v].pb(u);
	}
	for(int i = 0; i < maxn; i++)used[i] = false, sz[i] = 0;
	centroidDec(1);

}


