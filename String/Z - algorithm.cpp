vector<int> Zfunc(string &s) {
    int n=s.length();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) 
            z[i] = min(z[i-l],r-i+1);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])
            z[i]++;
        if(r<i+z[i]-1)
            l=i,r=i+z[i]-1;
    }
    return z;
}

int L = 0, R = 0;
for (int i = 1; i < n; i++) 
{
    if (i > R) 
    {
        L = R = i;
        while (R < n && s[R-L] == s[R]) 
        {
            R++;
        }
        z[i] = R-L; 
        R--;
    } 
    else 
    {
        int k = i-L;
        if (z[k] < R-i+1) 
        {
            z[i] = z[k];
        } 
        else 
        {
            L = i;
            while (R < n && s[R-L] == s[R]) 
            {
                R++;
            }
            z[i] = R-L; 
            R--;
        }
    }
}

