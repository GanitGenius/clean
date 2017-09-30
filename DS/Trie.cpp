{
	
// Maximum XOR Trie	

int x[N][M], nxt = 1, val[N]; //initially all numbers in x are -1
void add(int s){
	int i = 0, v = 0;
	for(int i=29;i>=0;i--){
		int bit=(s>>i)&1;
		if(x[v][bit] == 0)
			v = x[v][bit] = nxt ++;
		else
			v = x[v][bit];
		val[v]++;
	}
}
void del(int s){	
	int i = 0, v = 0, bit, vv;
	for(int i=29;i>=0;i--){
		bit=(s>>i)&1;
		v = x[v][bit];
		val[v]--;
	}
}
int query(int s){
	int i = 0, v = 0, ans = 0;
	for(int i=29;i>=0;i--){
		int bit=(s>>i)&1;
		if(bit == 1){
			if(x[v][0] && val[x[v][0]]){
				ans+=(1<<i);
				v=x[v][0];
			}
			else v=x[v][1];
		}else {
			if(x[v][1] && val[x[v][1]]){
				ans+=(1<<i);
				v=x[v][1];
			}
			else v=x[v][0];
		}
	}	
	return ans;
}

}