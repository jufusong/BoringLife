#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, ma, mb;
    char c;
    scanf("%d %d.%d", &n, &ma, &mb);
    int m = ma * 100 + mb;

    int K = (n * m - 1) / 100 + 1;
    for (int i = 1; i <= n; i++) {
      int t;
      scanf("%d", &t);
      K -= (t >= 50);
    }
    puts(K > 0 ? "NO" : "YES");
  }
  return 0;
}
