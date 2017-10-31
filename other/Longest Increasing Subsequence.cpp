#include "bits/stdc++.h"
using namespace std;

int n, a[maxn], best[maxn];

int main() {
// ios::sync_with_stdio(false), cin.tie(0);

// Input
cin >> n;
fr(i, n)cin >> a[i], best[i] = 0;

int mx_len = 1;
best[1] = 1;

for(int i = 2; i <= n; i++){
	if(a[i] > a[best[mx_len]]){
		best[++mx_len] = i;
		continue;
	}
	int lo = 1, hi = mx_len;
	while(lo < hi){
		int mid = (lo + hi) / 2;
		if(a[best[mid]] >= a[i])hi = mid;
		else lo = mid + 1;
 	}
 	best[hi] = i;
}
cout << mx_len;


}