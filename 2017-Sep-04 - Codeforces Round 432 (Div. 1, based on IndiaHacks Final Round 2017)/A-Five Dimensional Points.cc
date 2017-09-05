#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1004;

vector<vector<int>> a(1004);

bool check(int ix, int iy, int iz) {
  ll x = 0;
  for (int i = 0; i < 5; i++) {
    x += (a[iy][i] - a[ix][i]) * (a[iz][i] - a[ix][i]);
  }
  return x > 0;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  if (n > 500) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int t;
      cin >> t;
      a[i].push_back(t);
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (i != j && i != k) {
          if (check(i, j, k)) flag = false;
        }
      }
    }
    if (flag) ans.push_back(i + 1);
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
