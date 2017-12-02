// C(n, r)
int ncr[maxn][maxn];
// memset(ncr,0,sizeof(ncr));
for (int i = 0; ncr[i][0] = 1, i <= 5000; i++){
	// ncr[i][0]=1;
	for (int j = 1; j <= i; j++)
		ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
}

int modE(int n, int x){int res=1;while(x){if(x&1)res=(1ll*res*n)%MOD;n=(1ll*n*n)%MOD;x>>=1;}return res;}
LL modE(LL n, LL x, LL mod = MOD){	
	LL res = 1;	while(x){if(x & 1)res = (res * n) % mod;n = (1ll * n * n) % mod;x >>= 1;}
	return res;
}

