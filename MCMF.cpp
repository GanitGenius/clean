#include <bits/stdc++.h>
 
using namespace std;
#define MAXM 10101010
#define MAXN 120
#define pb push_back
#define mp make_pair
#define INF 1e9
#define F first
#define S second
 
 // https://www.hackerearth.com/submission/11951214/
struct edge{
	int to, f, c, cost;
	edge(){}
	edge(int _to, int _f, int _c, int _cost){
		to = _to;
		f = _f;
		c = _c;
		cost = _cost;
	}
};
 
edge ed[MAXM];
vector<int> g[MAXN];
int inq[MAXN];
int dist[MAXN];
pair<int, int> pai[MAXN];
int cur;
 
void add_edge(int u, int v, int cap, int rcap, int cost){
	ed[cur] = edge(v, 0, cap, cost);
	g[u].pb(cur++);
	
	ed[cur] = edge(u, 0, rcap, -cost);
	g[v].pb(cur++);
}
 
bool spfa(int src, int sink){
	queue<int> q;
	memset(inq, 0, sizeof inq);
	for (int i = 0; i <= MAXN; i++)
	{
		dist[i] = INF;
	}
	
	dist[src] = 0;
	inq[src] = 0;
	q.push(src);
	
	int u, v, w, cap, idx;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		
		//~ printf("estou em %d\n", u);
		inq[u] = 0;
		
		for (int i = 0; i < (int)g[u].size(); i++)
		{
			idx = g[u][i];
			v = ed[idx].to;
			cap = ed[idx].c - ed[idx].f;
			w = ed[idx].cost;
			
			if(dist[u] + w < dist[v] && cap > 0){
				dist[v] = dist[u] + w;
				pai[v] = mp(u, idx);
				if(!inq[v]){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
		
	}
	
	//~ printf("dist[sink] = %d\n", dist[sink]);
	return dist[sink] != INF;
}
 
int augment(int src, int sink, int &cost){
	int u = sink, v, mn = INF;
	int cap;
	
	while (u != src)
	{
		cap = ed[pai[u].S].c - ed[pai[u].S].f;
		mn = min(mn, cap);
		u = pai[u].F;
	}
	
	int c = 0;
	u = sink;
	while (u != src)
	{
		ed[pai[u].S].f += mn;
		ed[(pai[u].S)^1].f -= mn;
		c += ed[pai[u].S].cost;
		u = pai[u].F;
	}
	
	cost += (c * mn);
	return mn;
}
 
pair<int, int> mcmf(int src, int sink){
	int flow = 0;
	int cost = 0;
	
	int cnt = 0;
	while (spfa(src, sink))
	{
		
		flow += augment(src, sink, cost);
		//~ printf("flow = %d achei\n", flow);
	}
	
	return mp(flow, cost);
}
 
int main(){
	int n, src = 0, sink = 1, x;
	cur = 0;
	cin >> n;
	for (int i = 2; i < n + 2; i++)
	{
		add_edge(src, i, 1, 0, 0);
		for (int j = n+2; j < n+2+n; j++)
		{
			cin >> x;
			add_edge(i, j, 1, 0, x);
			
			if(i == 2) add_edge(j, sink, 1, 0, 0); 
		}
	}
	cout << mcmf(src, sink).S << "\n";
	
	return 0;
}



##################################	SHORTER	#########################################
#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
 
using namespace std;
 
const int INF = 1e9 + 9;
// https://www.hackerearth.com/submission/11937323/
struct edge {
    int fr, to;
    int flow, capacity;
    int cost;
    int back;
};
 
vector<vector<edge> > v;
 
void add_edge(int fr, int to, int capacity, int cost) {
    edge e1 = { fr, to, 0, capacity, cost, v[to].size() };
    edge e2 = { to, fr, 0, 0, -cost, v[fr].size() };
 
    v[fr].push_back(e1);
    v[to].push_back(e2);
}
 
int min_cost_max_flow(int n, int s, int t) {
    int cost = 0, flow = 0;
    
    while (flow < INF) {
        // cout << flow << endl;
        vector<int> d(n, INF), u(n), p(n), pe(n);
        d[s] = 0;
        deque<int> q;
        q.push_back(s);
        while (!q.empty()) {
            int st = q.front();
            q.pop_front();
            u[st] = 2;
            
            for (int i = 0; i < v[st].size(); ++i) {
                int to = v[st][i].to;
                if (d[to] > d[st] + v[st][i].cost && v[st][i].flow < v[st][i].capacity) {
                    if (u[to] == 0) {
                        q.push_back(to);
                    } else if (u[to] == 2) {
                        q.push_front(to);
                    }
                    u[to] = 1;
                    d[to] = d[st] + v[st][i].cost;
                    p[to] = st;
                    pe[to] = i;
                }
            }
        }
 
        if (d[t] == INF) {
            break;
        }
        
        int aug = INF - flow;
        for (int st = t; st != s; st = p[st]) {
            int pst = p[st];
            edge & e = v[pst][pe[st]];
            aug = min(aug, e.capacity - e.flow);
        }
        
        for (int st = t; st != s; st = p[st]) {
            int pst = p[st];
            edge & e = v[pst][pe[st]];
            e.flow += aug;
            v[st][e.back].flow -= aug;
            cost += e.cost * aug;
        }
        
        flow += aug;
    }
    
    return cost;
}
 
int main()
{
    int n;
    cin >> n;
    v.resize(2 * n + 2);
    
    for (int i = 0; i < n; ++i) {
        v[i + 1].reserve(n);
        v[i + n + 1].reserve(n);
        
        add_edge(0, i + 1, 1, 0);
        add_edge(i + n + 1, 2 * n + 1, 1, 0);
        
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            add_edge(i + 1, j + n + 1, 1, c);
        }
    }
	int s = 0, t = 2 * n + 1;
	n = 2 * n + 2;
 
	cout << min_cost_max_flow(n, s, t);
    return 0;
}

################################	READABLE	####################################
#include <bits/stdc++.h>
 
using namespace std;
 
#define wt second.second
#define nv second.first   
#define cp first.second
#define vv first.first
#define OO 1000000000000000000
#define oo 1000000000
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
// https://www.hackerearth.com/submission/11368928/
 
long long level[1000005];
int v[1000005];
int vis[1000005];
vector<pair<pair<int,int>, pair<int,int> > > adj[1000005];
vector<int> lazy[1000005];
int maxflow;
long long mincost;
 
void add_edge(int v, int u, int cap, int pes){
	lazy[v].pb(0);
	lazy[u].pb(0);
	adj[v].pb(mp(mp(u, cap), mp(adj[u].size(), pes)));
	adj[u].pb(mp(mp(v, 0), mp(adj[v].size()-1, -pes)));
}
 
int dij(int s, int t){
	priority_queue<pair<long long, int> > q;
	level[s] = 0;
	q.push(mp(0,s));
 
	while(!q.empty()){
		long long p = -q.top().ff;
		int v = q.top().ss;
		q.pop();
 
		for(int i = 0; i < adj[v].size(); i++){
			if(lazy[v][i]){
				adj[v][i].cp += lazy[v][i];
				lazy[v][i] = 0;
			}
			if(level[adj[v][i].vv] > level[v] + adj[v][i].wt && adj[v][i].cp > 0){
				level[adj[v][i].vv] = level[v] + adj[v][i].wt;
				q.push(mp(-level[adj[v][i].vv],adj[v][i].vv));
			}
		}
	}
 
	return level[t] == OO;
}
 
pair<int,long long> dfs(int x, int t, int flow){
	if(vis[x]) return mp(0,0);
	if(x == t) return mp(flow,0);
 	vis[x] = 1;
 
	for(; v[x] < adj[x].size(); v[x]++){
		pair<pair<int,int>, pair<int,int> > at = adj[x][v[x]];
		
		if(level[at.vv] == level[x] + at.wt && at.cp > 0){
			pair<int, long long> currflow;
			currflow.ff = min(flow,at.cp);
			currflow = dfs(at.vv, t, currflow.ff);
			currflow.ss += at.wt;
			if(currflow.ff){
				adj[x][v[x]].cp -= currflow.ff;
				lazy[at.vv][at.nv] += currflow.ff;
 
				vis[x] = 0;
				return currflow;
			}
		}
	}
	vis[x] = 0;
	return mp(0,0);
}
 
void dinic(int s,int t){
	while(1){
		for(int i = 0; i < 1000000; i++) level[i] = OO;
		if(dij(s,t)) break;
 
		memset(v, 0, sizeof v);
		pair<int,long long> temp;
		while(1){
			temp = dfs(s,t,oo);
			if(!temp.ff) break;
			maxflow += temp.ff;
			mincost += temp.ss;
		}
	}
}
 
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		add_edge(0,i,1,0);
		for(int j = 1; j <= n; j++){
			int x;
			scanf("%d",&x);
			add_edge(i,j+n+1,1,x);
		}		
		add_edge(i+n+1,n+1,1,0);
	}
	dinic(0,n+1);
	printf("%lld\n",mincost );
}