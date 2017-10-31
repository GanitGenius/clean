struct node {
	node *l, *r;
	ll sum ;
	node ( ) {
		l = r = 0 ;
		sum = 0 ;
	}
};
ii v [MAXN] ;
node * roots [MAXN] ;
int n, q ;
void update ( node * last , node * cur , int l , int r , int
	pos , int val ) {
	if ( l > pos || r < pos )
		return ;
	if ( l == r && r == pos ) {
		cur−>sum = last −>sum + val ;
		return ;
	}
	int mid = ( l+r ) / 2;
	if ( pos <= mid ) {
		cur−>l = new node ( ) ;
		cur−>r = last −>r ;
		update ( last −>l , cur−>l , l , ( l+r ) / 2 , pos , val ) ;
	}
	else {
		cur−>r = new node ( ) ;
		cur−>l = last −>l ;
		update ( last −>r , cur−>r , ( l+r ) /2+1, r , pos , val) ;
	}
	cur−>sum = cur−>l−>sum + cur−>r−>sum ;
}
void build ( node * cur , int l , int r ) {
	if ( l == r )
		return ;
	cur−>l = new node ( ) ;
	cur−>r = new node ( ) ;
	build ( cur−>l , l , ( l+r ) / 2 ) ;
	build ( cur−>r , ( l+r ) /2+1, r ) ;
}
ll get ( node * cur , int l , int r , int x , int y ) {
	if ( l > y || r < x )
		return 0 ;
	if ( l >= x && r <= y )
		return cur−>sum ;
	return get ( cur−>l , l , ( l+r ) / 2 , x , y ) + get ( cur−>r
		, ( l+r ) /2+1, r , x , y ) ;
}
ll get ( int l , int r ) {
	ll s = 0 ;
	while ( 1 ) {
		ll cur = get ( roots [ upper_bound ( v , v+n , ii ( s +1,
			n+1) ) − v ] , 1 , n , l , r ) ;
		if ( cur == s )
			return s +1;
		s = cur ;
	}
	return 0 ;
}
void solve ( ) {
	scanf ( "%d %d" , &n , &q ) ;
	for ( int i = 0 ; i < n ; i++){
		scanf ( "%d" , &v [ i ] . f s t ) ;
		v [ i ] . snd = i ;
	}
	sort ( v , v+n ) ;
	roots [ 0 ] = new node ( ) ;
	build ( roots [ 0 ] , 1 , n ) ;
	for ( int i = 1 ; i <= n ; i++){
		roots [ i ] = new node ( ) ;
		update ( roots [ i −1] , roots [ i ] , 1 , n , v [ i −1]. snd
			+1, v [ i −1]. f s t ) ;
	}
	int l , r ;
	while ( q−−){
		scanf ( "%d %d" , &l , &r ) ;
		printf ( "%ll d \n" , get ( l , r ) ) ;
	}
}
