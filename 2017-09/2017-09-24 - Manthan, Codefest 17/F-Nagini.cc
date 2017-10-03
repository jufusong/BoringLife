#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

typedef long long ll;

unsigned a[100000], b[100000];

int main(int argc, char *argv[]) {
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      unsigned* vec = (k > 0 ? a : b);
      unsigned c = abs(k);
      for (int i = l; i < r; i++) {
        auto x = vec[i];
        vec[i] = (x < c ? x : c);
      }
    } else {
      ll ans = 0;
      int l, r;
      scanf("%d%d", &l, &r);
      for (int i = l; i < r; i++) {
        ans += ((a[i] + b[i]) & ~((int)a[i] >> 31) & ~((int)b[i] >> 31));
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
