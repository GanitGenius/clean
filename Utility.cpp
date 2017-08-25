{

int modE(int n, int x){
	LL res = 1;
	while(x){
		if(x & 1)
			res = (res * n) % MOD;
		n = (1ll * n * n) % MOD;
		x >>= 1;
	}
	return res;
}

}
{

int inv[maxn], invfact[maxn], fact[maxn];
inv[1] = invfact[1] = 1, fact[1] = 1;
for(int i = 2; i < maxn; i++)	inv[i] = modE(i, MOD - 2), fact[i] = (1ll * fact[i - 1] * i) % MOD;
for(int i = 2; i < maxn; i++)	invfact[i] = (1ll * invfact[i - 1] * inv[i]) % MOD;

}
{

	
}