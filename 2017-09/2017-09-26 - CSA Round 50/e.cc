#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> a) {
  int b[4][4] = {0};
  int n = a.size();
  for (int i = 1; i <= n; i++) {
    int u = 0;
    if (i == 1) {
      u = 0;
    } else if (i == n) {
      u = 3;
    } else if (i & 1) {
      u = 2;
    } else {
      u = 1;
    }
    int val = a[i - 1], v = 0;
    if (val == n / 2) {
      v = 0;
    } else if (val == n / 2 + 1) {
      v = 3;
    } else if (val > n / 2) {
      v = 1;
    } else {
      v = 2;
    }
    if (u != v) {
      //      cout << i << " " << u << " " << v << endl;
      b[u][v]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) {
      int m = min(b[i][j], b[j][i]);
      ans += m;
      b[i][j] -= m;
      b[j][i] -= m;
    }
  }
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sum += b[i][j];
    }
  }
  if (sum) {
    ans = ans + sum - 1;
    if (sum == 6) ans--;
    if (sum != 3 && sum != 4 && sum != 6) {
      for (auto x : a) {
        cout << x << " ";
      }
      cout << endl;
      cout << sum << endl;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          cout << b[i][j] << " ";
        }
        cout << endl;
      }
    }
    assert(sum == 3 || sum == 4 || sum == 6);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = cal(a);
    for (int i = 0; i < n; i++) {
      a[i] = n + 1 - a[i];
    }
    ans = min(ans, cal(a));
    cout << ans << endl;
  }
  return 0;
}
