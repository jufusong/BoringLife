#include <bits/stdc++.h>

using namespace std;

int inverse(int a, int md) {
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
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", inverse(i, p));
  }
  return 0;
}
