#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> pre, rank;
  vector<int> op;

  DSU(int n) {
    rank = pre = vector<int>(n + 1);
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
      op.push_back(-fv);
    }
    pre[fu] = fv;
    op.push_back(fu);
  }

  int getStamp() {
    return op.size();
  }

  void restore(int stamp) {
    while (op.size() > stamp) {
      if (op.back() > 0) {
        pre[op.back()] = op.back();
      } else {
        rank[-op.back()]--;
      }
      op.pop_back();
    }
  }
}dsu(5e5 + 5);

struct A {
  int u, v, w, id;
  bool operator < (const A& x) {
    return w < x.w;
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<A> edge(m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    edge[i].id = i;
  }
  sort(edge.begin(), edge.end());
  vector<int> idx(m);
  for (int i = 0; i < m; i++) {
    idx[edge[i].id] = i;
  }
  int Q;
  scanf("%d", &Q);
  vector<map<int, vector<int>>> vq(Q);
  map<int, vector<int>> g;
  for (int i = 0; i < Q; i++) {
    int K;
    scanf("%d", &K);
    while (K--) {
      int id;
      scanf("%d", &id);
      id--;
      vq[i][edge[idx[id]].w].push_back(idx[id]);
    }
    for (auto& e : vq[i]) {
      g[e.first].push_back(i);
    }
  }
  vector<bool> ans(Q, true);
  map<int, vector<int>> b;
  for (int i = 0; i < m; i++) {
    b[edge[i].w].push_back(i);
  }
  for(auto& e1 : b) {
    int stamp = dsu.getStamp();
    int w = e1.first;
    for (auto q : g[e1.first]) {
      for (auto e : vq[q][w]) {
        int u = edge[e].u, v = edge[e].v;
        if (dsu.find(u) == dsu.find(v)) {
          ans[q] = false;
          break;
        }
        dsu.merge(u, v);
      }
      dsu.restore(stamp);
    }
    for (auto e : b[w]) {
      int u = edge[e].u, v = edge[e].v;
      dsu.merge(u, v);
    }
  }
  for (auto x : ans) {
    puts(x ? "YES" : "NO");
  }
  return 0;
}
