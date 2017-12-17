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
  int n;
  cin >> n;
  vector<int> a(n, 0), vec;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vec.push_back(a[i]);
    vec.push_back(a[i] + 1);
    vec.push_back(a[i] - 2);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  auto getIndex = [&vec](int n) {
    return lower_bound(vec.begin(), vec.end(), n) - vec.begin() + 1;
  };
  FenwickTree<long long> fw1(vec.size() + 1), fw2(vec.size() + 1);
  for (auto x : a) {
    fw1.update(getIndex(x), x);
    fw2.update(getIndex(x), 1);
  }
  long double ans = 0;
  for (auto x : a) {
    ans -= x * (fw2.query(vec.size() - 1) - fw2.query(getIndex(x + 1)) + fw2.query(getIndex(x - 2)));
    ans += fw1.query(vec.size() - 1) - fw1.query(getIndex(x + 1)) + fw1.query(getIndex(x - 2));
    fw1.update(getIndex(x), -x);
    fw2.update(getIndex(x), -1);
  }
  printf("%.0Lf\n", ans);
  return 0;
}
