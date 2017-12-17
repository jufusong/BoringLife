#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
const int mod = 1e9 + 7;

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
        f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return max(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

int solve(vector<int> a) {
  int n = a.size();
  SparseTable<int> sd(a);
  for (int k = 1; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      int mx = sd.query(i, i + k);
      a.push_back(mx);
    }
  }
  vector<pair<int, int>> st(1, {inf, -1});
  vector<int> L(a.size()), R(a.size());
  for (int i = 0; i < a.size(); i++) {
    while (a[i] > st.back().first) st.pop_back();
    L[i] = st.back().second;
    st.push_back({a[i], i});
  }
  st = vector<pair<int, int>>{{inf, a.size()}};
  for (int i = a.size() - 1; i >= 0; i--) {
    while (a[i] >= st.back().first) st.pop_back();
    R[i] = st.back().second;
    st.push_back({a[i], i});
  }
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int x = (i - L[i]), y = R[i] - i;
    ans = (ans + (long long) x * y % mod * a[i]) % mod;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  SparseTable<int> sd(a);
  for (int k = 1; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      int mx = sd.query(i, i + k);
      a.push_back(mx);
    }
  }
  vector<pair<int, int>> st(1, {inf, -1});
  vector<int> L(a.size()), R(a.size());
  for (int i = 0; i < a.size(); i++) {
    while (a[i] > st.back().first) st.pop_back();
    L[i] = st.back().second;
    st.push_back({a[i], i});
  }
  st = vector<pair<int, int>>{{inf, a.size()}};
  for (int i = a.size() - 1; i >= 0; i--) {
    while (a[i] >= st.back().first) st.pop_back();
    R[i] = st.back().second;
    st.push_back({a[i], i});
  }
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int x = (i - L[i]), y = R[i] - i;
    ans = (ans + (long long) x * y % mod * a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
