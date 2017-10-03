#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  auto dis = [](ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  };
  cout << (dis(ax, ay, bx, by) == dis(bx, by, cx, cy) && dis(ax, ay, cx, cy) != 4 * dis(ax, ay, bx, by) ? "Yes" : "No") << endl;
  return 0;
}
