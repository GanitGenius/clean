struct query{
    int l, r, d, idx;

    inline query() {}
    inline query(int a, int b, int c){
        idx = c;
        l = a, r = b, d = l / block_size;
    }

    inline bool operator < (const query& other) const{
        if (d != other.d) return (d > other.d);
        return ((d & 1) ? (r < other.r) : (r > other.r));
    }
} Q[MAX];

for (i = 0; i < q; i++){
    l = fastio::number();
    r = fastio::number();
    l--, r--;
    Q[i] = query(l, r, i);
}
sort(Q, Q + q);
a = 0, b = 0, xx = 0, res = 0;
for (i = 0; i < q; i++){
    l = Q[i].l, r = Q[i].r;
    while (a > l) insert(--a);
    while (b <= r) insert(b++);
    while (a < l) erase(a++);
    while (b > (r + 1)) erase(--b);
    out[Q[i].idx] = res ^ xx;
}
