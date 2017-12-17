#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int val;

vector<pair<int, int>> state;

int dfs(int now, int p) {
  if (now == 0) return 0;
  if (p == state.size()) return __builtin_popcount(now) * val;
  int ans = inf;
  if (state[p].first & now) {
    ans = dfs(now & (~state[p].first), p + 1) + state[p].second;
  }
  ans = min(ans, dfs(now, p + 1));
  return ans;
}

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  vector<int> dd(4);
  cin >> n;
  for (int i = 0; i < 4; ++i) {
    cin >> dd[i];
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 1; k < 4 && i + k < 4 && j + k < 4; k++) {
        int v = 0;
        for (int x = i; x <= i + k; x++) {
          for (int y = j; y <= j + k; y++) {
            v |= (1 << (x * 4 + y));
          }
        }
        state.push_back({v, dd[k]});
      }
    }
  }
  val = dd[0];
  vector<string> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  vector<int> f(n + 1, 1e9);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= i - 4 && j >= 0; j--) {
      int v = 0;
      for (int x = 0; x < 4; x++) {
        for (int y = j + 1; y <= i; y++) {
          if (y >= 1 && a[x][y - 1] == '*') {
            v |= (1 << (x * 4 + (y - i + 3)));
          }
        }
      }
      f[i] = min(f[i], f[j] + dfs(v, 0));
    }
  }
  cout << f[n] << endl;
  return 0;
}
