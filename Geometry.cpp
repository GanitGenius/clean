template<class T>
class Point {
	bool origin;
	T x, y;
	Point(T a, T b) : x(a), y(b){
		if(a == T(0) && b == T(0))	isOrigin = true;
		else	isOrigin = false;
	}
}
template<class T>
class Line {
	bool vertical, horizontal, passThruOrigin;
	T a, b, cc, m, c;
	Line(T x, T y, T z) : a(x), b(y), cc(z){
		// ax + by + cc = 0
		vertical = a? false: true;
		horizontal = b? false : true;
		passThruOrigin = c?false : true;
		this.toSlopeIntercept();
	}
	Line(T x, T y) : m(x), c(y){
		// y = mx + c
		this.toStandart();
	}
}