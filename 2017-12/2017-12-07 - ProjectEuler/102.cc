#include <bits/stdc++.h>

using namespace std;

template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes dist()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
};

template <class P> bool onSegment(const P &s, const P &e, const P &p) {
  P ds = p - s, de = p - e;
  return ds.cross(de) == 0 && ds.dot(de) <= 0;
}

template <class P>
bool insidePolygon(vector<P> vec, const P &p, bool strict = true) {
  int n = 0; // number of isects with line from p to (inf,p.y)
  for (auto i = vec.begin(), j = vec.end() - 1; i != vec.end(); j = i++) {
    // if p is on edge of polygon
    if (onSegment(*i, *j, p)) return !strict;
    // or: if (segDist(*i, *j, p) <= epsilon) return !strict;
    // increment n if segment intersects line from p
    n += (max(i->y, j->y) > p.y && min(i->y, j->y) <= p.y &&
          ((*j - *i).cross(p - *i) > 0) == (i->y <= p.y));
  }
  return n & 1; // inside if odd number of intersections
}

int main(int argc, char *argv[]) {
  int cnt = 0;
  vector<Point<int>> a(3);
  while (cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y) {
    cnt += insidePolygon(a, Point<int>(0, 0), false);
  }
  cout << cnt << endl;
  return 0;
}
