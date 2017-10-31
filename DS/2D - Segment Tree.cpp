#define MAXN 1030
int tree [ 4 * MAXN] [ 4 * MAXN] ;

void build_y ( int idxx , int lx , int rx , int idxy , int ly , int ry ) {
	if ( ly == ry ) {
		if ( lx == rx )
			tree [ idxx ] [ idxy ] = 0 ; // Valor i n i c i a l
		else
			tree [ idxx ] [ idxy ] = tree [ idxx * 2 ] [ idxy ] +
		tree [ idxx *2+ 1][ idxy ] ;
		return ;
	}
	build_y ( idxx , lx , rx , idxy *2 , ly , ( ly+ry ) / 2 ) ;
	build_y ( idxx , lx , rx , idxy *2+1, ( ly+ry ) / 2 + 1, ry ) ;
	tree [ idxx ] [ idxy ] = tree [ idxx ] [ idxy * 2] 
							+ tree [ idxx] [ idxy * 2 + 1];
}
void build_x ( int idx , int lx , int rx , int ly , int ry )
{
	if ( lx != rx ) {
		build_x ( id x *2 , lx , ( lx+rx ) / 2 , ly , ry ) ;
		build_x ( id x *2+1, ( lx+rx ) /2+1, rx , ly , ry ) ;
	}
	build_y ( idx , lx , rx , 1 , ly , ry ) ;
}
int get_y ( int idxx, int idxy, int ly, int ry, int y1, int y2 ) {
	if ( ly > y2 || ry < y1 )
		return 0 ;
	if ( ly >= y1 && ry <= y2 )
		return tree [ idxx ] [ idxy ] ;
	return get_y ( idxx , idxy *2 , ly , ( ly+ry ) / 2 , y1 , y2 )
	+ get_y ( idxx, idxy *2+1, ( ly+ry ) /2+1, ry, y1, y2 ) ;
}
int get_x ( int idxx, int lx, int rx, int idxy, int ly,	int ry, int x1, int x2, int y1, int y2) {
	if ( lx > x2 || rx < x1 )
		return 0 ;
	if ( lx >= x1 && rx <= x2 )
		return get_y (idxx, idxy, ly, ry, y1, y2) ;
	return get_x (idxx *2, lx, ( lx+rx ) / 2, idxy, ly, ry,	x1, x2, y1, y2) 
			+ get_x (idxx *2+1, ( lx+rx ) /2+1, rx, idxy, ly, ry, x1, x2, y1, y2);
}
void updatey (int idxx, int lx, int rx, int idxy, int ly, int ry, int py, int val) {
	if ( ly > py || ry < py )
		return ;
	if ( ly == ry ) {
		if ( lx == rx )
			tree [ idxx ] [ idxy ] += val ;
		else
		tree [ idxx ] [ idxy ] = tree [ idxx * 2 ] [ idxy ] 
								 + tree [ idxx *2+ 1][ idxy ] ;
		return ;
	}
	updatey (idxx, lx, rx, idxy *2, ly, ( ly+ry ) / 2, py, val);
	updatey (idxx, lx, rx, idxy *2+1, ( ly+ry ) /2+1, ry, py, val);
	tree [ idxx ] [ idxy ] = tree [ idxx ] [ idxy * 2] + tree [ idxx ] [ idxy *2+ 1];
}
void updatex(int idxx , int lx, int rx, int idxy, int ly, int ry, int px, int py, int val) {
	if ( lx > px || rx < px )
		return ;
	if ( lx != rx ) {
		updatex (idxx *2, lx, ( lx+rx ) / 2, idxy, ly, ry, px, py, val) ;
		updatex (idxx *2+1, ( lx+rx ) /2+1, rx, idxy, ly, ry, px, py, val);
	}
	updatey (idxx, lx, rx, idxy, ly, ry, py, val) ;
}