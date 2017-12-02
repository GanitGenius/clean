// LCA	BINARY LIFTING TECHNIQUE
int getNthParent(int v, int diff) {
	for (int i = 0; i < 31; i++)if ((diff >> i) & 1)	v = parent[i][v];
	return v;
}

int LCA(int v, int u) {
	if (level[v] > level[u])	swap(u, v);
	int diff = level[u] - level[v];
	u = getNthParent(u, diff);
	if (u == v)	return u;
	for (int i = 30; i >= 0; i--) {
		if (parent[i][u] != parent[i][v])	u = parent[i][u], v = parent[i][v];
	}
	return parent[0][u];
}

for(int i = 1; i < 31; i++)
	for(int j = 1; j <= N; j++)
		parent[i-1][j] = -1;
dfs(1, 0, 1);
for(int i=1; i<31; i++)
	for(int j=1; j <= N; j++)
		if(parent[i-1][j] != -1)
			parent[i][j] = parent[i-1][parent[i-1][j]];