// TRIE
int tot = 0, nxt[maxn][26];
void add(string s){
	int cur = 0;
	for(int i = 0; i < (int)s.size(); i++){
		if(!nxt[cur][s[i] - 'a'])nxt[cur][s[i] - 'a'] = ++tot;
		cur = nxt[cur][s[i] - 'a'];
	}
}
bool find(string s){
	Not Tested Yet / Check if cur is end of some node ?? 
	int cur = 0;
	for(auto c : s){
		if(!nxt[cur][c - 'a'])return false;
		cur = next[cur][c - 'a'];
	}
	return true;
}
