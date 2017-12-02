// a[i], the elments
// m[i], number of times it appers
// O(Nsqrt(N))   
// http://codeforces.com/blog/entry/49812
  bitset<MAXK> dp;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = 0; (1<<x) <= m[i]; x++) {
      dp |= (dp << (a[i]*(1<<x)));
      m[i] -= (1<<x);
    }
    dp |= (dp << (a[i]*m[i]));
  }
  // now, dp[k] equals the k-th bit of f(n)


// Other Implementation
// Not Tested May be Wrong
for(int i = 1; i <= n; i++){
    int k = m[i];
    for(int h = 1; k; h += h){
        k -= (h = min(h, k));
        dp |= (dp << a[i] * h);
    }
}