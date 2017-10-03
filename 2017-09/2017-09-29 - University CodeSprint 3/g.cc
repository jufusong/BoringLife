#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000005;

namespace fw {
  ll in[N];

  int lowbit(int n) {return n & (-n);}

  void update(int p, ll val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }

  ll query(int p) {
    ll sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}

vector<pair<int, int>> edge;

namespace DSU {
  vector<int> pre, rank, sz;
  vector<tuple<int, int, ll>> op;
  vector<map<int, int>> mp;

  void init(int n) {
    sz = rank = pre = vector<int>(n + 1);
    mp = vector<map<int, int>>(n + 1);
    for (int i = 1; i <= n; i++) {
      pre[i] = i;
    }
  }

  int find(int u) {
    return u == pre[u] ? pre[u] : find(pre[u]);
  }

  void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv) return;
    if (rank[fu] > rank[fv]) {
      swap(fu, fv);
    }
    if (rank[fu] == rank[fv]) {
      rank[fv]++;
      op.push_back({1, fv, 1});
    }
    pre[fu] = fv;
    sz[fv] += sz[fu];
    op.push_back({2, fu, fv});
    op.push_back({5, fv, sz[fu]});
  }

  void add(int id, int c) {
    sz[id] = 1;
    op.push_back({5, id, 1});
    int u = edge[id].first, v = edge[id].second;
    fw::update(c, 1);
    op.push_back({3, c, 1});
    auto solve = [&c, &id](int k) {
      if (mp[k][c]) {
        int fu = find(mp[k][c]), fv = find(id);
        ll sx = (ll)sz[fu] * (sz[fu] + 1) / 2, sy = (ll)sz[fv] * (sz[fv] + 1) / 2, ss = (ll)(sz[fu] + sz[fv]) * (sz[fu] + sz[fv] + 1) / 2;
        fw::update(c, -sx);
        fw::update(c, -sy);
        fw::update(c, ss);
        op.push_back({3, c, -sx});
        op.push_back({3, c, -sy});
        op.push_back({3, c, ss});
        merge(mp[k][c], id);
      } else {
        mp[k][c] = id;
        op.push_back({4, k, c});
      }
    };
    solve(u), solve(v);
  }

  int getStamp() {
    return op.size();
  }

  void restore(int stamp) {
    while ((int)op.size() > stamp) {
      int tp, x;
      ll y;
      tie(tp, x, y) = op.back();
      if (tp == 1) {
        rank[x]--;
      } else if (tp == 2) {
        pre[x] = x;
      } else if (tp == 3) {
        fw::update(x, -y);
      } else if (tp == 4){
        mp[x][y] = 0;
      } else if (tp == 5) {
        sz[x] -= y;
      }
      op.pop_back();
    }
  }
}

ll a[120005];
vector<tuple<int, int, int>> Q;

void cdq(int L, int R, vector<tuple<int, int, int, int>> vec) {
  int stamp = DSU::getStamp();
  int m = (L + R) / 2;
  vector<tuple<int, int, int, int>> vl, vr;
  for (auto x : vec) {
    int id, c, l, r;
    tie(id, c, l, r) = x;
    if (l <= L && r > R) {
      DSU::add(id, c);
    } else {
      if (l <= m) vl.push_back(x);
      if (r - 1 >= m + 1) vr.push_back(x);
    }
  }
  if (L == R) {
    if (get<0>(Q[L]) == 2) {
      int l, r;
      tie(ignore, l, r) = Q[L];
      a[L] = fw::query(r) - fw::query(l - 1);
    } else if (get<0>(Q[L]) == 3) {
      int sz = DSU::sz[DSU::find(get<1>(Q[L]))];
      a[L] = (ll)sz * (sz + 1) / 2;
    }
  } else {
    cdq(L, m, vl);
    cdq(m + 1, R, vr);
  }
  DSU::restore(stamp);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  DSU::init(n);
  vector<pair<int, int>> b(n);
  edge = b;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    b[i] = {c, 0};
    edge[i] = {u, v};
  }
  int q;
  cin >> q;
  vector<tuple<int, int, int, int>> vec;
  for (int i = 0; i < q; i++) {
    int tp, x, y;
    cin >> tp >> x;
    if (tp <= 2) cin >> y;
    Q.push_back({tp, x, y});
    if (tp == 1) {
      vec.push_back({x, b[x].first, b[x].second, i});
      b[x] = {y, i};
    }
  }
  for (int i = 1; i < n; i++) {
    vec.push_back({i, b[i].first, b[i].second, q});
  }
  cdq(0, q - 1, vec);
  for (int i = 0; i < q; i++) {
    if (get<0>(Q[i]) != 1) {
      cout << a[i] << endl;
    }
  }
}
