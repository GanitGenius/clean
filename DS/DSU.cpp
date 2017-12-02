// Union Find

struct DSU{
	int par[maxn], sz[maxn], len[maxn];
	DSU(){
		for(int i = 0; i < maxn; i++) par[i] = i, sz[i] = 1;
	}	
	int find(int v){  return par[v] = (par[v] == v ? v : find(par[v])); }	
	void merge(int u, int v){
		u = find(u), v = find(v);
		if(sz[u] > sz[v]) par[v] = u, sz[u] += sz[v];
		else  par[u] = v, sz[v] += sz[u];
	}
};