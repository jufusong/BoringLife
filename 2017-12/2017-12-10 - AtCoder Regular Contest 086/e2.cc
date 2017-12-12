#include <bits/stdc++.h>

template <class T> struct SparseTable {
  std::vector<std::vector<T>> f;
  std::vector<int> lg;
  SparseTable() {}
  SparseTable(const std::vector<T> &a) { init(a); }
  void init(const std::vector<T> &a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, std::vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

struct LCA {
  const std::vector<std::vector<int>>& g;
  SparseTable<std::pair<int, int>> st;
  std::vector<int> sp;
  std::vector<int> dep, ST, ED;

  LCA(const std::vector<std::vector<int>>& graph, int root = 1) : g(graph) {
    int sz = graph.size();
    dep = ST = ED = std::vector<int>(sz);
    dfs(root, -1, 0);
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < sp.size(); i++) {
      vec.emplace_back(ST[sp[i]], sp[i]);
    }
    st.init(vec);
  }
  
  void dfs(int u, int fa, int d) {
    dep[u] = d + 1;
    ST[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u, d + 1);
        sp.push_back(u);
      }
    }
    ED[u] = (int)sp.size() - 1;
  }

  int query(int u, int v) {
    int l = ST[u], r = ST[v];
    if (l > r) std::swap(l, r);
    return st.query(l, r).second;
  }
};

struct CompressedTree {
  LCA lca;
  std::vector<std::vector<int>> g;
  CompressedTree(const std::vector<std::vector<int>>& graph, int root = 1) : lca(graph, root), g(graph.size()) {}

  int construct(std::vector<int> vertex) {
    auto cmp = [this](int u, int v) { return this->lca.ST[u] < lca.ST[v]; };
    sort(vertex.begin(), vertex.end(), cmp);
    int n = vertex.size();
    for (int i = 1; i < n; i++) {
      vertex.push_back(lca.query(vertex[i], vertex[i - 1]));
    }
    sort(vertex.begin(), vertex.end(), cmp);
    vertex.erase(unique(vertex.begin(), vertex.end()), vertex.end());
    std::vector<int> sd;
    for (auto v : vertex) {
      g[v].clear();
      for (; !sd.empty() && !(lca.ST[sd.back()] <= lca.ST[v] && lca.ST[v] <= lca.ED[sd.back()]); sd.pop_back());
      if (!sd.empty()) {
        g[sd.back()].push_back(v);
      }
      sd.push_back(v);
    }
    return vertex[0];
  }
};

using namespace std;

const int mod = 1e9 + 7;

long long f[200005][2];

void dfs(int u, const vector<vector<int>>& g) {
  if (f[u][1] == -1) {
    f[u][0] = f[u][1] = 1;
    return;
  }
  f[u][0] = 1;
  f[u][1] = 0;
  vector<pair<long long, long long>> vec(1, {1, 1});
  for (auto v : g[u]) {
    dfs(v, g);
    vec.push_back({f[v][0], f[v][1]});
  }
  auto v2 = vec;
  for (int i = 1; i < vec.size(); i++) {
    f[u][0] = f[u][0] * (vec[i].first + vec[i].second) % mod;
    vec[i].first = (vec[i].first * vec[i - 1].first) % mod;
  }
  long long now = 1;
  for (int i = vec.size() - 1; i >= 1; i--) {
    f[u][1] = (f[u][1] + v2[i].second * now % mod * vec[i - 1].first) % mod;
    now = (now * v2[i].first) % mod;
  }
  f[u][0] = (f[u][0] - f[u][1] + mod) % mod;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  ++n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p + 1].push_back(i);
  }
  CompressedTree ct(g);
  vector<vector<int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[ct.lca.dep[i]].push_back(i);
  }
  long long ans = 0;
  vector<long long> P2(n, 1);
  for (int i = 1; i < n; i++) {
    P2[i] = P2[i - 1] * 2 % mod;
  }
  for (int i = 1; i <= n && !a[i].empty(); ++i) {
    int root = ct.construct(a[i]);
    for (auto x : a[i]) {
      f[x][1] = -1;
    }
    dfs(root, ct.g);
    ans = (ans + f[root][1] * P2[n - a[i].size()]) % mod;
  }
  cout << ans << endl;
  return 0;
}
