#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int inf = 1e9;

vector<tuple<int, int, int>> g[N];
pair<int, int> f[N][2];

void dfs(int u, int fa) {
  pair<int, int> a;
  auto add = [](pair<int, int> x, pair<int, int> y) {
    return make_pair(x.first + y.first, x.second + y.second);
  };
  auto sub = [](pair<int, int> x, pair<int, int> y) {
    return make_pair(x.first - y.first, x.second - y.second);
  };
  int cnt = 0;
  pair<int, int> mx{-1, -1};
  for (auto e : g[u]) {
    int v, x, y;
    tie(v, x, y) = e;
    if (v != fa) {
      dfs(v, u);
      if ((x ^ y) == 0) {
        a = add(a, f[v][0]);
      } else {
        if (y == 2) {
          if (f[v][1].first == f[v][0].first) {
            a = add(add(a, f[v][1]), {0, 1});
            cnt++;
            mx = max(mx, sub(f[v][1], f[v][0]));
          } else {
            a = add(a, f[v][0]);
          }
        } else {
          cnt++;
          a = add(add(a, f[v][1]), {0, 1});
        }
      }
    }
  }
  a = add(a, {-cnt / 2, 0});
  f[u][0] = a;
  f[u][1] = add(a, {1, 0});
  if (cnt & 1) {
    f[u][1] = a;
  }
  if (mx.first != -1) {
    cout << u << endl;
    if (cnt & 1) {      
      f[u][0] = sub(sub(f[u][0], mx), {0, 1});
    } else {
      cout << u << " " << mx.first << " " << mx.second << endl;
      cout << a.first << " " << a.second << endl;
      f[u][1] = add(sub(a, mx), {1, -1});
    }
  }
  printf("%d %d %d %d %d\n", u, f[u][0].first, f[u][0].second, f[u][1].first, f[u][1].second);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    g[a].emplace_back(b, c, d);
    g[b].emplace_back(a, c, d);
  }
  dfs(1, -1);
  cout << f[1][0].first << " " << f[1][0].second << endl;
  return 0;
}
