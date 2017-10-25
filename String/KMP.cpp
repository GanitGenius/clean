vector<int> prefix_function (string Z) {
    int n = (int) Z.length();
    vector<int> F (n);
     F[0]=0;
    for (int i=1; i<n; ++i) {
        int j = F[i-1];
        while (j > 0 && Z[i] != Z[j])
            j = F[j-1];
        if (Z[i] == Z[j])  ++j;
        F[i] = j;
    }
    return F;
}


void failure_kmp(string Z){
	int n = (int)Z.length();
	F[0] = 0;
	for(int i = 1, j; j = F[i - 1], i < n; i++){
		while(Z[i] != Z[j] && j > 0)	j = F[j - 1];
		if(Z[i] == Z[j]) j++;
		F[i] = j;
	}
}