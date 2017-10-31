// Next Greater Element
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], nge[maxn];
stack<int> candid;

int main(){
// Input


nge[n] = -1, candid.push(n);
for(int i = n - 1; i > 0; i--){
	while(!candid.empty() && a[candid.top()] <= a[i])candid.pop();
	nge[i] = !candid.empty() ? -1 : a[candid.top()];
	candid.push(i);
}

}