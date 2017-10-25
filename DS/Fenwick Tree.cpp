// SIMPLE
int BIT[1000], a[1000], n;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

// POINT UPDATE RANGE QUERY + RANGE UPDATE POINT QUERY
template<class T>
struct fenwick_range_update
{
	int sz;
	T tr[maxn];

	void init(int _sz)
	{
		sz = _sz + 1;
		memset(tr, 0, sizeof(tr));
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
		return ans;
	}

	void update(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}

	void update(int l, int r, T val)
	{
		update(l, val);
		update(r + 1, -val);
	}
};

// RANGE UPDATE RANGE QUERY
template<class T>
struct fenwick
{
	int sz;
	fenwick_range_update<T> t0, t1;	
	
	void init(int _sz)
	{
		sz = _sz;
		t0.init(sz + 1);
		t1.init(sz + 1);
	}

	void update(int l, int r, T val)
	{
		t0.update(l, r, val);
		t1.update(l, r, -(l - 1) * val);
		t1.update(r + 1, sz, (r - l + 1) * val);
	}

	T query(int idx) { return t0.query(idx) * idx + t1.query(idx); }
	T query(int l, int r) { return query(r) - query(l - 1); }
};


{

// 2D BIT I
int a[N][N];
void inc(int x, int y, int z){
	for(int i = x; i <= n;i += i&-i)
		for(int j = y; j <= m; j += j&-j)
			a[i][j] ^= z;
}
int ask(int x, int y){
	int z = 0;
	for(int i = x; i; i ^= i&-i)
		for(int j = y; j; j ^= j&-j)
			z ^= a[i][j];
	return z;
}

IMPLEMENTATION II
ll bit[ms][ms];
void upd(int r, int c, ll v) {
	for(int x = r; x < ms; x += x & -x) {
		for(int y = c; y < ms; y += y & -y) {
			bit[x][y] += v;
		}
	}
}

void upd(int r1, int r2, int c1, int c2, ll v) {
	upd(r1, c1, v);
	upd(r1, c2 + 1, -v);
	upd(r2 + 1, c1, -v);
	upd(r2 + 1, c2 + 1, v);
}

ll qry(int r, int c) {
	ll ans = 0;
	for(int x = r; x > 0; x -= x & -x) {
		for(int y = c; y > 0; y -= y & -y) {
			ans += bit[x][y];
		}
	}
	return ans;
}


	
}