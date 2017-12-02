struct Node {
	int sum;
	Node(){	sum = 0;	}
	Node operator+(Node other){
		Node node;
			// 
		return node;
	}
};
struct SegmentTree {
	int sarr[maxn * 4], lzy[maxn * 4];
	
	SegmentTree(){	memset(sarr, 0, sizeof sarr);	memset(lzy, 0, sizeof lxy);}

	void build(int id = 1, int l = 0, int r = n - 1) {
		if (r == l) {	//	l + 1 == r
			sarr[id] = arr[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		sarr[id] = sarr[id * 2] + sarr[id * 2 + 1];
	}

	void upd(int p, int x, int id = 1, int l = 0, int r = n - 1) {
		if (r == l) {	//	l = r - 1 = p
			sarr[id] += x;
			return;
		}
		int mid = (l + r) >> 1;
		if (p <= mid)
			upd(p, x, id * 2, l, mid);
		else
			upd(p, x, id * 2 + 1, mid + 1, r);
		sarr[id] = sarr[id * 2] + sarr[id * 2 + 1];
	}

	int get(int st, int en, int id = 1, int l = 0, int r = n - 1) {
		if (st > r || en < l)	return 0;
		if (st <= l && en >= r)	return sarr[id];
		int mid = (l + r) >> 1;
		return get(st, en, id * 2, l, mid) +
		get(st, en, id * 2 + 1, mid + 1, r);
	}

	void updRange(int st, int en, int x, int id = 1, int l = 0, int r = n - 1) {
		if (lzy[id] != 0) {
			sarr[id] += (r - l + 1) * lzy[id];
			if (l != r) {
				lzy[2 * id] += lzy[id];
				lzy[2 * id + 1] += lzy[id];
			}
			lzy[id] = 0;
		}
		if (st > r || en < l)	return;
		if (st <= l && en >= r) {
			sarr[id] += (r - l + 1) * x;
			if (l != r) {
				lzy[2 * id] += x;
				lzy[2 * id + 1] += x;
			}
			return;
		}
		int mid = (l + r) >> 1;
		updRange(st, en, x, 2 * id, l, mid);
		updRange(st, en, x, 2 * id + 1, mid + 1, r);
		sarr[id] = sarr[2 * id] + sarr[2 * id + 1];
	}

	int getRange(int st, int en, int id = 1, int l = 0, int r = n - 1) {
		if (st > r || en < l)	return 0;
		if (lzy[id] != 0) {
			sarr[id] += (r - l + 1) * lzy[id];
			if (l != r) {
				lzy[2 * id] += lzy[id];
				lzy[2 * id + 1] += lzy[id];
			}
			lzy[id] = 0;
		}
		if (st <= l && en >= r)	return sarr[id];
		int mid = (l + r) >> 1;
		return getRange(st, en, id * 2, l, mid) +
		getRange(st, en, id * 2 + 1, mid + 1, r);
	}

} sgt;



				
// CHECK AGAIN ONLY IMPLEMENTED FOR MAX IN (0, POS)
struct Node {
	Node *left, *right;
	int lf, rt, sum, lazy;
	Node(int _lf, int _rt) { 
		this->left = this->right = NULL; this->lf = _lf, this->rt = _rt; this->sum = this->lazy = 0; 
	}

	void add(int pos, int x) {
		if(this->lazy != 0){
			this->sum = max(this->sum, this->lazy);
			if(this->left != NULL)	this->left->lazy = max(this->left->lazy, this->lazy);
			if(this->right != NULL)	this->right->lazy = max(this->right->lazy, this->lazy);
			this->lazy = 0;	
		}
		if (this->lf == this->rt){	
			this->sum = max(this->sum, x);
			return;
		}
		int mid = (this->lf + this->rt) / 2;
		if (pos <= mid) {
			if (this->left == NULL)	this->left = new Node(this->lf, mid);
			this->left->add(pos, x);
						// mx = max(mx, this->left->sum);
		}else{
			if (this->right == NULL) this->right = new Node(mid + 1, this->rt);
			this->right->add(pos, x);
						// mx = max(mx, this->right->sum);
		}
		int mx = this->sum;
		if (this->left != NULL)	mx = max(mx, this->left->sum);
		if (this->right != NULL)	mx = max(mx, this->right->sum);
		this->sum = mx;	
	}
	int get(int pos){
		if(this->lazy != 0){
			this->sum = max(this->sum, this->lazy);
			if(this->left != NULL)	this->left->lazy = max(this->left->lazy, this->lazy);
			if(this->right != NULL)	this->right->lazy = max(this->right->lazy, this->lazy);
			this->lazy = 0;	
		}
		if(this->lf == this->rt)	return this->sum;
		if(this->rt <= pos)	return this->sum;
		int mid, mx = 0;
		mid = (this->lf + this->rt) / 2;
		if(pos <= mid && this->left != NULL)	mx = max(mx, this->left->get(pos)); 

		if(pos > mid){
			if(this->left != NULL)	mx = max(mx, this->left->get(pos));
			if(this->right != NULL)	mx = max(mx, this->right->get(pos));
		}
		return mx;
	}
	void destroy(){
		if(this->left != NULL)this->left->destroy();
		if(this->right != NULL)this->right->destroy();
		delete this->left;
		delete this->right;
	}
};






struct node_ap
{
	int sum, lazy, lazy_ap;

	node_ap() {sum = 0; lazy = 0; lazy_ap = 0;}
	node_ap(int val)
	{
		sum = val;
		lazy = 0;
		lazy_ap = 0;
	}
};

node_ap temp, broken;

node_ap merge(node_ap l, node_ap r)
{
	temp.sum = l.sum + r.sum;
	temp.lazy = 0;
	temp.lazy_ap = 0;
	return temp;
}

struct segment_tree_ap
{
	node_ap tr[4 * MAXN];

	void update(int l, int r, int idx)
	{
		if(tr[idx].lazy)
		{
			tr[idx].sum += (r - l + 1) * tr[idx].lazy;

			if(l != r)
			{
				tr[2 * idx + 1].lazy += tr[idx].lazy;
				tr[2 * idx + 2].lazy += tr[idx].lazy;
			}

			tr[idx].lazy = 0;
		}	

		if(tr[idx].lazy_ap)
		{
			int mid = (l + r) >> 1;
			tr[idx].sum += ((r - l + 1) * (r - l + 2) / 2) * tr[idx].lazy_ap;

			if(l != r)
			{
				tr[2 * idx + 1].lazy_ap += tr[idx].lazy_ap;
				tr[2 * idx + 2].lazy_ap += tr[idx].lazy_ap;
				tr[2 * idx + 2].lazy += tr[idx].lazy_ap * (mid - l + 1);
			}

			tr[idx].lazy_ap = 0;
		}
	}

	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx] = node_ap(a[l]);
			return;
		}

		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}	

	void update(int qL, int qR, int val, int prog, int l, int r, int idx)
	{
		update(l, r, idx);

		if(qL > r || l > qR)
			return;

		if(qL <= l && r <= qR)
		{
			tr[idx].lazy += val + (l - qL) * prog;
			tr[idx].lazy_ap += prog;
			update(l, r, idx);
			return;
		}

		int mid = (l + r) >> 1;
		update(qL, qR, val, prog, l, mid, 2 * idx + 1);
		update(qL, qR, val, prog, mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	node_ap query(int qL, int qR, int l, int r, int idx)
	{
		update(l, r, idx);

		if(l > qR || r < qL)
			return broken;

		if(qL <= l && r <= qR)
			return tr[idx];

		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}                 
};




######################	USAGE	#############################
// COUNT NUMBER OF INVERSIONS
// NOT COMPLETELY VERIFIED
void build(int id, int l, int r) {
	if (p == 0) {	//	l + 1 == r
		sarr[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	sarr[id] = sarr[id * 2] + sarr[id * 2 + 1];
	
	sort(a + l, a + mid + 1);
	sort(a + mid + 1, a + r + 1);

	// Inter-Segment Inversions
	for(int i = l; i <= mid; i++){
		LL tmp = lower_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid);
		sarr[id] += tmp;
	}
}

