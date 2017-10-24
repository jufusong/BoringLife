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
  int n;
  cin >> n;
  FenwickTree fw(n);
  vector<int> a(n), vec(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vec[i] = a[i];
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  auto index = [&vec](int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
  };
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    fw.update(index(a[i]), 1);
    ans += i + 1 - fw.query(index(a[i]));
  }
  cout << ans << endl;
  return 0;
}
