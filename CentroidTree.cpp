#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
#define fi first
#define se second
#define pb push_back
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fr(i, n) for (int i = 1; i <= (int)(n); ++i)
#define all(x) (x).begin(), (x).end()
#define ret return 0
const int maxn = 5e5 + 5;
int n, sz[maxn];
vector<int> T[maxn];
bool used[maxn];
char res[maxn];

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


void centroidDec(int v, char ch) {
	computeSz(v, v);
	int c = centroid(v, sz[v] / 2, v);
	res[c] = ch;
	used[c] = true;

	for (auto u : T[c])if (!used[u])
		centroidDec(u, ch + 1);
}

int main() {
	// ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	fo(i, n - 1) {
		int u, v; cin >> u >> v;
		T[u].pb(v), T[v].pb(u);
	}
	fo(i, maxn)used[i] = false, sz[i] = 0;

	centroidDec(1, 'A');
	fr(i, n)cout << res[i] << ' ';

}


