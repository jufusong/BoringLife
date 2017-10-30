#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    string op;
    int v;
    cin >> op >> v;
    int t;
    if (op[0] == '|') {
      t = 1;
    } else if (op[0] == '&') {
      t = 2;
    } else {
      t = 3;
    }
    a[i] = {t, v};
  }
  int b[11][2] = {0};
  auto cal = [&](int x) {
    for (auto e : a) {
      int t = e.first, v = e.second;
      if (t == 1) {
        x |= v;
      } else if (t == 2) {
        x &= v;
      } else {
        x ^= v;
      }
    }
    return x;
  };
  for (int i = 0; i < 10; i++) {
    int x = (1 << i);
    int t = cal(x);
    b[i][1] = (t & (1 << i));
    x = 0;
    t = cal(x);
    b[i][0] = (t & (1 << i));
  }
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < 10; i++) {
    if (b[i][0] && b[i][1]) {
      y ^= (1 << i);
      x ^= (1 << i);
    } else if (!b[i][0] && b[i][1]) {
      x ^= (1 << i);
    } else if (b[i][0] && !b[i][1]) {
      x ^= (1 << i);
      z ^= (1 << i);
    }
  }
  cout << 3 << endl;
  cout << "& " << x << endl;
  cout << "| " << y << endl;
  cout << "^ " << z << endl;
  return 0;
}
