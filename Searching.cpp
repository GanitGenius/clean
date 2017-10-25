{
// Ternary Search
double func(double x)
{ 
return -1*1*x*x + 2*x +3; 
}


double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     double x = l;
    return func(x);
}

}
{

// Ternary Search 2
while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(f(mid) > f(mid+1)) {
        hi = mid;
    }
    else {
        lo = mid+1;
    }
}

}
{
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

}

