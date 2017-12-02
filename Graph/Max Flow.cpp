// const int nod = 5000;
const int INF = 987654321;

typedef tuple<int, int, int> EE;

class AnotherMaxFlow {
public:
    bool used[maxn];
    struct edge { int to, cap, rev; };
    vector<edge> G[maxn];

    void add_edge(int from, int to, int cap) {
        edge e;
        e.to = to, e.cap = cap, e.rev = G[to].size();
        G[from].push_back(e);
        e.to = from, e.cap = 0, e.rev = G[from].size() - 1;
        G[to].push_back(e);
    }

    int dfs(int v, int t, int f) {
        if (v == t)    return f;
        used[v] = 1;
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            memset(used, 0, sizeof used);
            int f = dfs(s, t, INF);
            if (f == 0)return flow;
            flow += f;
        }
        return flow;
    }
};