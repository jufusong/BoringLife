#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;
vector<int> g[N];
bool a[N];

void dfs(int u, int fa) {
  a[u] = (a[fa] ^ 1);
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
  }
  cout << (ll)sum * (n - sum) - n + 1 << endl;
  return 0;
}
