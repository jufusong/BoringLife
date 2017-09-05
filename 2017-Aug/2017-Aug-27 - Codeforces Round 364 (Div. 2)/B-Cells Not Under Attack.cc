#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  ll ans = (ll)n * n;
  vector<bool> a(n), b(n);
  int s1 = n, s2 = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (!a[x]) {
      ans -= s2;
      s1--;
      a[x] = true;
    }
    if (!b[y]) {
      ans -= s1;
      s2--;
      b[y] = true;
    }
    cout << ans << " ";
  }
  return 0;
}
