#include <bits/stdc++.h>

using namespace std;

int Inverse(int a, int md) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main(int argc, char *argv[]) {
  int x, y;
  cin >> x >> y;
  cout << Inverse(x, y) << endl;
  return 0;
}
