#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int inf = 1e9;

vector<int> a, pr;

void dfs(int x, int p) {
  a.push_back(x);
  for (int j = p; j < pr.size() && (ll)x * pr[j] <= inf; j++) {
    dfs(x * pr[j], j);
  }
}

int main(int argc, char *argv[]) {
  vector<bool> b(105);
  for (int i = 2; i <= 100; i++) {
    if (!b[i]) {
      pr.push_back(i);
      for (int j = i + i; j <= 100; j += i) {
        b[j] = true;
      }
    }
  }
  dfs(1, 0);
  sort(a.begin(), a.end());
  vector<int> f(a.size(), inf), g(a.size());
  f[0] = 0;
  int L, R, P;
  cin >> L >> R >> P;
  for (int i = 2; i <= P; i++) {
    for (int j = 0, h = 0; j < a.size(); j++) {
      if (a[j] % i == 0) {
        while (a[h] < a[j] / i) h++;
        f[j] = min(f[j], f[h] + 1);
        if (f[j] + i <= P) g[j] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] >= L && a[i] <= R) ans += g[i];
  }
  cout << ans << endl;
  return 0;
}
