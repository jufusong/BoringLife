#include <bits/stdc++.h>

using namespace std;

int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int v;
  cin >> v;
  return v;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i] = query(i, 0);
  }
  for (int i = 0; i < n; i++) {
    b[i] = query(0, i);
  }
  vector<int> ans;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    vector<int> c(n);
    for (int j = 0; j < n; j++) {
      c[j] = (a[j] ^ i);
    }
    bool flag = true;
    for (int j = 0; j < n; j++) {
      int t = (c[0] ^ b[j]);
      if (t >= n || c[t] != j) {
        flag = false;
      }
    }
    if (flag) {
      if (!cnt) {
        cnt = 1;
        ans = c;
      } else {
        cnt++;
      }
    }
  }
  cout << "!" << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
