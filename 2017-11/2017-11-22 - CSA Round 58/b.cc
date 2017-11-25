#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
  vector<int> in;
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
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    n = (1 << n);
    FenwickTree fw(n);
    vector<pair<int, int>> a;
    for (int i = 0, t; i < n; i++) {
      scanf("%d", &t);
      a.emplace_back(t, i);
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    int k = 0;
    for (auto e : a) {
      printf("%d ", k);
      fw.update(e.second + 1, 1);
      int x = e.second;
      for (int j = 0; (1 << j) <= n; j++) {
        int l = x / (1 << j) * (1 << j);
        if (fw.query(l + (1 << j)) - fw.query(l) + 1 >= (1 << j)) {
          k = max(k, j);
        }
      }
    }
    puts("");
  }
  return 0;
}
