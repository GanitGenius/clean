{
// Ternary Search
double func(double x)
{ 
return -1*1*x*x + 2*x +3; 
}


double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     double x = l;
    return func(x);
}

}
{

// Ternary Search 2
while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(f(mid) > f(mid+1)) {
        hi = mid;
    }
    else {
        lo = mid+1;
    }
}

}
{
// Union Find
void initialize( int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
    Arr[ i ] = i ;
    size[ i ] = 1;
  }
}

void weighted-union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
  }
    else
    {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
  }

}

int root (int Arr[ ] ,int i)
{
    return Arr[i] = ( Arr[i]== i ? i : root(Arr[i]) ); 
}

}

