#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    vector<set<long long>> v1(n + 1), v2(n + 1);
    for (int i = 4; i <= n; ++i) {
      for (int j = 2; j + 1 < i; j++) {
        if (a[j - 1] == a[i - 1] - a[j]) {
          v1[i].insert(a[j - 1]);
        }
      }
    }
    for (int i = n - 3; i >= 1; --i) {
      for (int j = n - 1; j - 1 > i; --j) {
        if (a[n] - a[j] == a[j - 1] - a[i]) {
          v2[i].insert(a[n] - a[j]);
        }
      }
    }
    bool flag = false;
    for (int i = 4; i <= n - 3 && !flag; i++) {
      for (auto x : v1[i]) {
        if (v2[i].count(x)) {
          flag = true;
          break;
        }
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
