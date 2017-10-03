#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
};
//*判断线段相交
bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while (T--) {
    vector<Point> a[2];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 4; j++) {
        double x, y;
        cin >> x >> y;
        a[i].push_back({x, y});
      }
    }
    bool flag = false;
    for (int zz = 0; zz < 2; zz++) {
      swap(a[0], a[1]);
      double dx = a[1][3].x - a[0][3].x, dy = a[1][3].y - a[0][3].y;
      dx *= 2e9;
      dy *= 2e9;
      for (int i = 0; i < 3; i++) {
        auto tt = Line(a[1][i], {a[1][i].x + dx, a[1][i].y + dy});
        for (int j = 0; j < 3; j++) {
          flag |= inter(tt, {a[0][j], a[0][(j + 1) % 3]});
        }
      }
    }
    printf("Case #%d: %s\n", cas++, flag ? "YES" : "NO");
  }

  return 0;
}
