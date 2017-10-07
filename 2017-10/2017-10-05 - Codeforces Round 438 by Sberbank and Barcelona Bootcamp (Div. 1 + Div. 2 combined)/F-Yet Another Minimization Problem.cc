#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e16;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> f(K + 1, vector<ll>(n + 1, inf));
  f[0][0] = 0;
  int pl = 1, pr = 1;
  ll ans = 0;
  function<void(int, int, int, int, int)> cal = [&](int k, int L, int R, int cl, int cr) {
    if (L > R) return;
    int M = (L + R) / 2;
    int p = -1;
    for (int i = cl; i <= cr && i < M; i++) {
      while (pr <= M) ans += b[a[pr]]++, pr++;
      while (pr - 1 > M) pr--, ans -= --b[a[pr]];
      while (pl < i + 1) ans -= --b[a[pl]], pl++;
      while (pl > i + 1) pl--, ans += b[a[pl]]++;
      if (f[k - 1][i] + ans < f[k][M]) {
        f[k][M] = f[k - 1][i] + ans;
        p = i;
      }
    }
    cal(k, L, M - 1, cl, p);
    cal(k, M + 1, R, p, cr);
  };
  for (int i = 1; i <= K; i++) {
    cal(i, 1, n, 0, n);
  }
  cout << f[K][n] << endl;
  return 0;
}
