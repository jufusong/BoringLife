#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> cnt(26);
  for (auto c : a[0]) {
    cnt[c - 'a']++;
  }
  for (int i = 1; i < n; i++) {
    vector<int> vec(26);
    for (auto c : a[i]) {
      vec[c - 'a']++;
    }
    if (vec != cnt) {
      cout << "-1" << endl;
      return 0;
    }
  }
  bool flag = false;
  for (auto x : cnt) {
    flag |= (x > 1);
  }
  vector<int> b(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i] += (a[i][j] != a[0][j]);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      bool ok = true;
      for (int k = 1; k < n; k++) {
        int err = b[k] - (a[k][i] != a[0][i]) - (a[k][j] != a[0][j]) + (a[k][j] != a[0][i]) + (a[k][i] != a[0][j]);
        ok &= (err == 2 || (err == 0 && flag));
      }
      if (ok) {
        swap(a[0][i], a[0][j]);
        cout << a[0] << endl;
        return 0;
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
