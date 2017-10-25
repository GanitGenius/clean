// C(n, r)
memset(C,0,sizeof(C));
C[0][0]=1;
for (int i = 1; C[i][0]=1, i <= 5000; i++)
	// C[i][0]=1;
	for (int j = 1; j <= i; j++)
		C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;

int modE(int n, int x){int res=1;while(x){if(x&1)res=(1ll*res*n)%MOD;n=(1ll*n*n)%MOD;x>>=1;}return res;}
LL modE(LL n, LL x, LL mod = MOD){	
	LL res = 1;	while(x){if(x & 1)res = (res * n) % mod;n = (1ll * n * n) % mod;x >>= 1;}
	return res;
}



int inv[maxn], invfact[maxn], fact[maxn];
inv[1] = invfact[1] = 1, fact[1] = 1;
for(int i = 2; i < maxn; i++)	inv[i] = modE(i, MOD - 2), fact[i] = (1ll * fact[i - 1] * i) % MOD;
for(int i = 2; i < maxn; i++)	invfact[i] = (1ll * invfact[i - 1] * inv[i]) % MOD;

