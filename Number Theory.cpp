//
int factor[maxn];
void sieve(){
	memset(factor, 0, sizeof factor);
	factor[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!factor[i]){
			factor[i] = i;
			if(1ll * i * i < maxn)
			for(int j = i*i; j < maxn; j+=i)if(!factor[j])factor[j] = i;
		}
	}
}

// inverse mod p.
// http://codeforces.com/blog/entry/5457?#comment-106714
inv[1] = 1;
for (int i = 2; i < maxn; ++i)
	inv[i] = (MOD - 1ll * (MOD/i) * inv[MOD%i] % MOD) % MOD;


int inv[maxn], invfact[maxn], fact[maxn];
inv[0] = invfact[0] = 1, fact[0] = 1;
inv[1] = invfact[1] = 1, fact[1] = 1;
for(int i = 2; i < maxn; i++)	inv[i] = modE(i, MOD - 2), fact[i] = (1ll * fact[i - 1] * i) % MOD;
for(int i = 2; i < maxn; i++)	invfact[i] = (1ll * invfact[i - 1] * inv[i]) % MOD;


int inv(int a) { return modE(a, MOD-2); }
