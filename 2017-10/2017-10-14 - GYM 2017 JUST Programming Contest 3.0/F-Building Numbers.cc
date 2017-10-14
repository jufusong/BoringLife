#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = a[i - 1];
      ll t;
      scanf("%lld", &t);
      while (t != 1) {
        if (t & 1) a[i]++;
        a[i]++;
        t /= 2;
      }
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", a[r] - a[l - 1]);
    }
  }
  return 0;
}
