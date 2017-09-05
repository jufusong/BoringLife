#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e18;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> c(n), d(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> c[i] >> d[i];
    c[i]--;
    g[c[i]].push_back(i);
  }
  bool flag = true;
  for (int i = n - 1; i >= 0 && flag; i--) {
    for (auto v : g[i]) {
      ll x = a[v] - b[v];
      if (inf / d[v] >= x) {
        b[i] -= d[v] * x;
        if (b[i] < -inf) {
          flag = false;
          break;
        }
      } else {
        flag = false;
        break;
      }
    }
    if (b[i] >= a[i]) {
      b[c[i]] += b[i] - a[i];
      b[i] = a[i];
    }
  }
  cout << (flag && a[0] <= b[0]? "YES" : "NO") << endl;
  return 0;
}
