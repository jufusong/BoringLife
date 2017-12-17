#include <bits/stdc++.h>

using namespace std;

template <class T> struct FenwickTree {
  std::vector<T> in;
  int N;
  FenwickTree(int N) : N(N), in(N) {}
  int lowbit(int n) {return n & (-n);}
  void update(int p, T val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  string s;
  cin >> n >> m >> s;
  FenwickTree<int> fw(n + 1);
  vector<set<int>> se(256);
  vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    se[s[i]].insert(i + 1);
    fw.update(i + 1, 1);
  }
  for (int i = 0; i < m; ++i) {
    int L, R;
    char c;
    cin >> L >> R >> c;
    auto get = [&fw, &n](int v) {
      int low = 1, high = n;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (fw.query(mid) < v) low = mid + 1;
        else high = mid - 1;
      }
      return low;
    };
    int l = get(L), r = get(R);
    while (true) {
      auto it = se[c].lower_bound(l);
      if (it == se[c].end() || *it > r) break;
      vis[*it - 1] = true;
      fw.update(*it, -1);
      se[c].erase(it);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) putchar(s[i]);
  }
  return 0;
}
