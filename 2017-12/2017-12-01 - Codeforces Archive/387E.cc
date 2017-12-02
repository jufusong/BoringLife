#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  std::vector<int> in;
  int N;
  FenwickTree(int N) : N(N) {
    in.assign(N + 1, 0);
  }
  int lowbit(int n) {return n & (-n);}
  void update(int p, int val) {
    for (int i = p; i <= N; i += lowbit(i)) {
      in[i] += val;
    }
  }
  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<int> a(n, 0), R(n, 0), L(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> vis(n + 1);
  for (int i = 0; i < K; ++i) {
    int t;
    cin >> t;
    vis[t] = true;
  }
  FenwickTree fw(n);
  vector<pair<int, int>> st(1, {0, 0});
  for (int i = 0; i < n; ++i) {
    if (vis[a[i]]) {
      while (a[i] < st.back().first) st.pop_back();
      st.push_back({a[i], i + 1});
    } else {
      auto it = lower_bound(st.begin(), st.end(), pair<int, int>{a[i], i + 1});
      L[i] = (--it)->second;
    }
  }
  st.clear();
  st.push_back({0, n + 1});
  for (int i = n - 1; i >= 0; --i) {
    if (vis[a[i]]) {
      while (a[i] < st.back().first) st.pop_back();
      st.push_back({a[i], i + 1});
    } else {
      auto it = lower_bound(st.begin(), st.end(), pair<int, int>{a[i], 0});
      R[i] = (--it)->second;
    }
  }
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; ++i) {
    fw.update(i + 1, 1);
    if (!vis[a[i]]) {
      vec.push_back({a[i], i});
    }
  }
  sort(vec.begin(), vec.end());
  long long ans = 0;
  for (auto e : vec) {
    int p = e.second;
    ans += fw.query(R[p] - 1) - fw.query(L[p]);
    fw.update(p + 1, -1);
  }
  cout << ans << endl;
  return 0;
}
