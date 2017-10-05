#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 100005;

vector<int> g[N];
ll K, ans = 1;

void dfs(int u, int fa) {
  ll x = K - (fa ? 2 : 1);
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      ans = ans * x-- % mod;
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n >> K;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = K;
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
